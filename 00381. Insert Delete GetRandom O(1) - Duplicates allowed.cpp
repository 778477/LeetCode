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
 
 381. Insert Delete GetRandom O(1) - Duplicates allowed
 
 Design a data structure that supports all following operations in average O(1) time.
 
 Note: Duplicate elements are allowed.
 insert(val): Inserts an item val to the collection.
 remove(val): Removes an item val from the collection if present.
 getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
 Example:
 
 // Init an empty collection.
 RandomizedCollection collection = new RandomizedCollection();
 
 // Inserts 1 to the collection. Returns true as the collection did not contain 1.
 collection.insert(1);
 
 // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
 collection.insert(1);
 
 // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
 collection.insert(2);
 
 // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
 collection.getRandom();
 
 // Removes 1 from the collection, returns true. Collection now contains [1,2].
 collection.remove(1);
 
 // getRandom should return 1 and 2 both equally likely.
 collection.getRandom();
 
 */


/**
 
 Array/Hash Table/Design
 
 lettcode 380的变种，设置map对应的index 为 vector<int>* 即可。注意vector<int> 保持顺序
 
 28 / 28 test cases passed.
 Status: Accepted
 Runtime: 72 ms
 
 */

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand((unsigned)time(NULL));
        vals.clear();
        table.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = false;
        if(table.find(val) == table.end()){
            table[val] = new vector<unsigned long>(0);
            flag = true;
        }
        
        vals.push_back(val);
        unsigned long idx = vals.size() - 1;
        table[val]->insert(lower_bound(table[val]->begin(), table[val]->end(), idx), idx);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(table.find(val) != table.end()){
            
            if(vals.back() == val){
                vals.pop_back();
            } else{
                unsigned long idx = table[val]->back();
                int backVal = vals.back();
                vals[idx] = backVal;
                vals.pop_back();
                table[backVal]->pop_back();
                table[backVal]->insert(lower_bound(table[backVal]->begin(), table[backVal]->end(), idx), idx);
            }
            
            table[val]->pop_back();
            if(table[val]->size() < 1) table.erase(val);
            
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(vals.size() > 0) return vals[rand()%vals.size()];
        return NULL;
    }
private:
    vector<int> vals;
    map<int, vector<unsigned long> *> table;
};


//["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove",
// "getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]


//[[],[10],[10],[20],[20],[30],[30],[10],[10],[30],[30],[],[],[],[],[],[],[],[],[],[]]

int main(){
    
    RandomizedCollection set;
    cout<<set.getRandom()<<endl;
    //
    cout<<set.insert(10)<<endl;
    cout<<set.insert(10)<<endl;
    cout<<set.insert(20)<<endl;
    cout<<set.insert(20)<<endl;
    cout<<set.insert(30)<<endl;
    cout<<set.insert(30)<<endl;
    //
    cout<<set.remove(10)<<endl;
    cout<<set.remove(10)<<endl;
    cout<<set.remove(30)<<endl;
    cout<<set.remove(30)<<endl;
    
    for(int i=0;i<10;i++) cout<<set.getRandom()<<endl;
    
    
    
    return 0;
}
