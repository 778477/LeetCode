//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 347. Top K Frequent Elements
 
 Given a non-empty array of integers, return the k most frequent elements.
 
 For example,
 Given [1,1,1,2,2,3] and k = 2, return [1,2].
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

 
 */

/**
 
 20 / 20 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int, int> cnt;
        for(int num : nums){
            ++cnt[num];
        }

        priority_queue<pair<int, int>> q;
        for(auto i : cnt){
            q.push(make_pair(i.second, i.first));
        }
        
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solve;
    
    
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = solve.topKFrequent(nums, 1);
    
    for(int i : ans){
        cout<<i<<endl;
    }
    
    return 0;
}
