
//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy on 2017/9/19.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 416. Partition Equal Subset Sum
 
 Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 
 Note:
 Each of the array element will not exceed 100.
 The array size will not exceed 200.
 Example 1:
 
 Input: [1, 5, 11, 5]
 
 Output: true
 
 Explanation: The array can be partitioned as [1, 5, 5] and [11].
 Example 2:
 
 Input: [1, 2, 3, 5]
 
 Output: false
 
 Explanation: The array cannot be partitioned into equal sum subsets.
 
 */

/**
 
 104 / 104 test cases passed.
 Status: Accepted
 Runtime: 26 ms
 
 一开始，暴力枚举01状态超时。时间复杂度大概是(2^(nums.length))
 
 改成dp，空间复杂度开销还好(bool 类型 （100*200/2）1w左右的bit)
 
 时间复杂度大概是 10000(最大划分数)*200(最大数组个数)
 
 另外，使用numeric中的accumulate可快速求和，第三参数0表示初始值
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) return false;
        int val = sum/2;
        
        bool *dp = (bool *)malloc(sizeof(bool) * (val+5));
        memset(dp, false, sizeof(bool) * (val+5));
        dp[0] = true;
        for (int i = 0;i<nums.size(); ++i){
            for(int j = val; j>= nums[i]; --j){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        
        bool ans = dp[val];
        free(dp);
        return ans;
    }
};

//[2，7，9，12]

int main(int argc, const char * argv[]) {
    
    Solution solve;
    vector<int> nums = {2,7,9,12};
    
    cout<<solve.canPartition(nums)<<endl;
    
    
    return 0;
}
