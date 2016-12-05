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
#include <functional>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

/*
 
 347. Top K Frequent Elements
 Total Accepted: 41203
 Total Submissions: 90710
 Difficulty: Medium
 Contributors: Admin
 Given a non-empty array of integers, return the k most frequent elements.
 
 For example,
 Given [1,1,1,2,2,3] and k = 2, return [1,2].
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 Subscribe to see which companies asked this question
 */



/*
 
 20 / 20 test cases passed.
 Status: Accepted
 Runtime: 422 ms
 
 */


class Solution {
public:
    Solution(){
        _maxFrequent = 0;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        for_each(nums.begin(), nums.end(), [&](const int num){
            
            if(table.count(num)){
                int oldF = table[num];
                frequentTable[oldF].erase(iterTable[num]);
                iterTable.erase(num);
            }
            
            ++table[num];
            _maxFrequent = _maxFrequent > table[num] ? _maxFrequent : table[num]; // update maxFrequent
            frequentTable[table[num]].push_back(num);
            iterTable[num] = --frequentTable[table[num]].end();
            
        });
        
        while(k > 0){
            vector<int> tmp;
            copy(frequentTable[_maxFrequent].begin(), frequentTable[_maxFrequent].end(), back_inserter(tmp));
            
            //            sort(tmp.begin(), tmp.end(), less<int>());
            
            if(tmp.size() <= k){
                k -= tmp.size();
                for_each(tmp.begin(), tmp.end(), [&](const int num){
                    ans.push_back(num);
                });
                
            } else{
                for(int i=0;i<k;i++){
                    ans.push_back(tmp[i]);
                }
                k = 0;
            }
            
            --_maxFrequent;
        }
        
        return ans;
    }
private:
    int _maxFrequent;
    map<int,int> table;
    map<int, list<int>> frequentTable;
    map<int, list<int>::iterator> iterTable;
};


int main(){
    Solution solve;
    vector<int> nums({5,3,1,1,1,3,73,1});
    
    vector<int> ans = solve.topKFrequent(nums, 1);
    
    for_each(ans.begin(), ans.end(), [](const int num){
        cout<<num<<endl;
    });
    
    
    return 0;
}

