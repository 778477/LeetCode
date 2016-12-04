//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

/*
 
 460. LFU Cache
 Total Accepted: 1239
 Total Submissions: 7169
 Difficulty: Hard
 Contributors: 1337c0d3r , fishercoder
 Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and set.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
 
 Follow up:
 Could you do both operations in O(1) time complexity?
 
 Example:
 
    LFUCache cache = new LFUCache( 2 ); // capacity

    cache.set(1, 1);
    cache.set(2, 2);
    cache.get(1);       // returns 1
    cache.set(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.set(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4

 */

 /*
  
  LFU 是 最近最不常用页面置换算法(Least Frequently Used)，
  区别于 LRU 最近最少使用页面置换算法(Least Recently Used)。
  
  LFU 对过去命中多次的缓存有加权逻辑，被访问的频率越高，被淘汰的几率越少
  LRU 则没有频率的概念，最近最常用使用，则被淘汰的几率越少。 
  
  没有什么比增加capacity来得更靠谱了。
  如果 capacity 有限的情况下，LRU 和 LFU 只不过是对用户访问行为的不同策略的一种博弈。 看不出谁好谁坏
  
  */


 /*

  // use map
  23 / 23 test cases passed.
  Status: Accepted
  Runtime: 529 ms
  Submitted: 2 minutes ago

  
  // use unordered_map
  23 / 23 test cases passed.
  Status: Accepted
  Runtime: 292 ms
  Submitted: 0 minutes ago

  how to choose between map and unordered_map ?
  
                         | map              | unordered_map
  ---------------------------------------------------------
  element ordering       | strict weak      | n/a
                         |                  |
  common implementation  | balanced tree    | hash table
                         | or red-black tree|
                         |                  |
  search time            | log(n)           | O(1) if there are no hash collisions
                         |                  | Up to O(n) if there are hash collisions
                         |                  | O(n) when hash is the same for any key
                         |                  |
  Insertion time         | log(n)+rebalance | Same as search
                         |                  |
  Deletion time          | log(n)+rebalance | Same as search
                         |                  |
  needs comparators      | only operator <  | only operator ==
                         |                  |
  needs hash function    | no               | yes
                         |                  |
  common use case        | when good hash is| In most other cases.
                         | not possible or  |
                         | too slow. Or when|
                         | order is required|
  
  */


class LFUCache {
public:
    LFUCache(int capacity) {
        _capcaity = capacity;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        
        fList[cache[key].second].erase(kIterTable[key]); // remove
        cache[key].second++;
        fList[cache[key].second].push_back(key);
        kIterTable[key] = --fList[cache[key].second].end();
        
        if(fList[_minFrequent].size() < 1){
            _minFrequent = cache[key].second;
        }
        cout<<cache[key].first<<endl;
        return cache[key].first;
    }
    
    void set(int key, int value) {
        if(_capcaity <= 0) return ;
        
        // update old new refresh
        if(get(key) != -1){
            cache[key].first = value;
            return ;
        }
        
        // set new key
        if(cache.size() == _capcaity){
            int evictedKey = fList[_minFrequent].front();
            fList[_minFrequent].pop_front();
            kIterTable.erase(evictedKey);
            cache.erase(evictedKey);
        }
        
        _minFrequent = 1;
        fList[_minFrequent].push_back(key);
        kIterTable[key] = --fList[_minFrequent].end();
        cache[key] = {value,_minFrequent};
    
    }
private:
    int _capcaity;
    int _minFrequent;
    
    map<int,pair<int, int>> cache; // store key -> {value, frequent}
    map<int,list<int>> fList; // frequent -> list<int> keys
    map<int,list<int>::iterator> kIterTable; // key -> list::iterator
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */



int main(){
    
    LFUCache cache(2);
    
    cache.set(1, 1);
    cache.set(2, 2);
    cache.get(1);       // returns 1
    cache.set(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.set(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
    
    
    return 0;
}

