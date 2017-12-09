//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 740. Delete and Earn

 Given an array nums of integers, you can perform operations on the array.
 
 In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
 
 You start with 0 points. Return the maximum number of points you can earn by applying such operations.
 
 Example 1:
 Input: nums = [3, 4, 2]
 Output: 6
 Explanation:
 Delete 4 to earn 4 points, consequently 3 is also deleted.
 Then, delete 2 to earn 2 points. 6 total points are earned.
 Example 2:
 Input: nums = [2, 2, 3, 3, 3, 4]
 Output: 9
 Explanation:
 Delete 3 to earn 3 points, deleting both 2's and the 4.
 Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
 9 total points are earned.
 Note:
 
 The length of nums is at most 20000.
 Each element nums[i] is an integer in the range [1, 10000].
 
 
 
 */

/**
 
 
 46 / 46 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
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
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int, int> cnts;
        vector<int> tmps;
        for(int num : nums){
            if(!cnts[num]){
                tmps.push_back(num);
            }
            ++cnts[num];
        }
        
        sort(tmps.begin(), tmps.end());
        vector<vector<int>> dp(tmps.size() + 1,vector<int>(2,0));
        
        int preVal = -1;
        for(unsigned i = 1; i <= tmps.size(); ++i){
            int val = tmps[i-1];
            
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            
            dp[i][1] = (val - preVal == 1 ?  dp[i-1][0] + val * cnts[val] :  max(dp[i-1][0],dp[i-1][1]) + val * cnts[val]);
            
            preVal = val;
        }
        
        return max(dp[tmps.size()][0],dp[tmps.size()][1]);
    }
};


/**
 Wrong Answer
 [10,8,4,2,1,3,4,8,2,9,10,4,8,5,9,1,5,1,6,8,1,1,6,7,8,9,1,7,6,8,4,5,4,1,5,9,8,6,10,6,4,3,8,4,10,8,8,10,6,4,4,4,9,6,9,10,7,1,5,3,4,4,8,1,1,2,1,4,1,1,4,9,4,7,1,5,1,10,3,5,10,3,10,2,1,10,4,1,1,4,1,2,10,9,7,10,1,2,7,5]
 
 Expected: 338
 
 
 */

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {10,8,4,2,1,3,4,8,2,9,10,4,8,5,9,1,5,1,6,8,1,1,6,7,8,9,1,7,6,8,4,5,4,1,5,9,8,6,10,6,4,3,8,4,10,8,8,10,6,4,4,4,9,6,9,10,7,1,5,3,4,4,8,1,1,2,1,4,1,1,4,9,4,7,1,5,1,10,3,5,10,3,10,2,1,10,4,1,1,4,1,2,10,9,7,10,1,2,7,5};
    Solution solve;
    
    cout<<solve.deleteAndEarn(nums)<<endl;
    return 0;
}

