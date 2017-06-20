//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
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
 
 
 341. Flatten Nested List Iterator
 
 Total Accepted: 36654
 Total Submissions: 89705
 Difficulty: Medium
 Contributor: LeetCode
 Given a nested list of integers, implement an iterator to flatten it.
 
 Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 
 Example 1:
 Given the list [[1,1],2,[1,1]],
 
 By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 
 Example 2:
 Given the list [1,[4,[6]]],
 
 By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 
 
 */


/*
 
 递归模拟栈，直接初始化要vector装好数据
 
 44 / 44 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 
 */



// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    void configNums(const NestedInteger i,vector<int>& nums){
        if(i.isInteger()){
            nums.push_back(i.getInteger());
        } else {
            vector<NestedInteger> list = i.getList();
            for(NestedInteger j : list){
                configNums(j, nums);
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        nums.clear();
        for(NestedInteger i : nestedList){
            configNums(i, nums);
        }
        index = 0;
    }
    
    int next() {
        if(hasNext()){
            return nums[index++];
        }
        
        return -1;
    }
    
    bool hasNext() {
        return index < nums.size();
    }
private:
    vector<int> nums;
    unsigned long index;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(){
    
    
    
    return 0;
}
