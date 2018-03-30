//
//  main.cpp
//  whiteBorad-leetcode
//
//  Created by 郭妙友 on 2018/3/30.
//  Copyright © 2018年 郭妙友. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 
 673. Number of Longest Increasing Subsequence
 
 Given an unsorted array of integers, find the number of longest increasing subsequence.
 
 Example 1:
 Input: [1,3,5,4,7]
 Output: 2
 Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
 Example 2:
 Input: [2,2,2,2,2]
 Output: 5
 Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
 Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
 
 */

/**
 223 / 223 test cases passed.
 Status: Accepted
 Runtime: 45 ms
 */

class Solution {
    public:
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<pair<int, int>> dp(nums.size(),make_pair(1, 1));
        int LIS_MaxLen = 1;
        int ans = 0;
        
        for(int i=0; i<nums.size(); ++i){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == dp[j].first + 1){
                        dp[i].second = dp[i].second + dp[j].second;
                    } else if(dp[i].first < dp[j].first + 1){
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }
                }
            }
            
            if(dp[i].first == LIS_MaxLen){
                ans += dp[i].second;
            }
            else if(dp[i].first > LIS_MaxLen){
                LIS_MaxLen = dp[i].first;
                ans = dp[i].second;
            }
        }
        
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    vector<int> nums = {1,2,3,1,2,3,1,2,3};
    cout<<solve.findNumberOfLIS(nums)<<endl;
    return 0;
}

