//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 
 560. Subarray Sum Equals K
 
 Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 
 Example 1:
 Input:nums = [1,1,1], k = 2
 Output: 2
 Note:
 The length of the array is in range [1, 20,000].
 The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 
 
 */

/**
 
 80 / 80 test cases passed.
 Status: Accepted
 Runtime: 639 ms
 
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
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        
        vector<int> sum(nums.size(),0);
        
        for(size_t i = 0;i<nums.size();++i){
            sum[i] = nums[i] + (i ? sum[i-1] : 0);
        }
        
        for(size_t i = 0;i<nums.size();++i){
            for(size_t j=i;j<nums.size();++j){
                if(sum[j] - sum[i] + nums[i] == k) ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,0,1};
    
    Solution solve;
    
    cout<<solve.subarraySum(nums, 2)<<endl;
    
    return 0;
}
