//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 380. Insert Delete GetRandom O(1)
 
 Design a data structure that supports all following operations in average O(1) time.
 
 insert(val): Inserts an item val to the set if not already present.
 remove(val): Removes an item val from the set if present.
 getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 Example:
 
 // Init an empty set.
 RandomizedSet randomSet = new RandomizedSet();
 
 // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 randomSet.insert(1);
 
 // Returns false as 2 does not exist in the set.
 randomSet.remove(2);
 
 // Inserts 2 to the set, returns true. Set now contains [1,2].
 randomSet.insert(2);
 
 // getRandom should return either 1 or 2 randomly.
 randomSet.getRandom();
 
 // Removes 1 from the set, returns true. Set now contains [2].
 randomSet.remove(1);
 
 // 2 was already in the set, so return false.
 randomSet.insert(2);
 
 // Since 2 is the only number in the set, getRandom always return 2.
 randomSet.getRandom();
 Subscribe to see which companies asked this question.
 
 
 */


/**
 Array/Hash Table/Design
 
 * 注意 不要使用 map<int,vector<int>::iterator> 在insert,remove中 iterator会失效。map在find和erase等操作中会出现 runtime error
 
 18 / 18 test cases passed.
 Status: Accepted
 Runtime: 53 ms
 
 */


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned)time(NULL));
        vals.clear();
        table.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(table.find(val) != table.end()) return false;
        
        vals.push_back(val);
        table[val] = vals.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(table.find(val) == table.end()) return false;
        
        int tmp = vals.back();
        vals[table[val]] = tmp;
        table[tmp] = table[val];
        vals.pop_back();
        table.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(vals.size() > 0) return vals[rand()%vals.size()];
        return 0;
    }
private:
    vector<int> vals;
    map<int, unsigned long> table;
};


int main(){
    
    RandomizedSet set;
    cout<<set.getRandom()<<endl;
    cout<<set.insert(1)<<endl;
    cout<<set.remove(2)<<endl;
    cout<<set.insert(2)<<endl;
    cout<<set.getRandom()<<endl;
    cout<<set.remove(1)<<endl;
    cout<<set.insert(2)<<endl;
    cout<<set.getRandom()<<endl;
    
    return 0;
}
