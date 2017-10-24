//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 611. Valid Triangle Number
 
 Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
 
 Example 1:
 Input: [2,2,3,4]
 Output: 3
 Explanation:
 Valid combinations are:
 2,3,4 (using the first 2)
 2,3,4 (using the second 2)
 2,2,3
 Note:
 The length of the given array won't exceed 1000.
 The integers in the given array are in the range of [0, 1000].
 */

/**
 枚举两边，查第三边满足条件个数
 220 / 220 test cases passed.
 Status: Accepted
 Runtime: 402 ms
 
 枚举一边，查两边满足条件的个数
 220 / 220 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for(auto i = nums.size() - 1; i > 1; --i){
            unsigned long l = i-1,r = 0;
            while(r < l){
                if(nums[r] + nums[l] > nums[i]){
                    ans += (l-r);
                    --l;
                } else {
                    ++r;
                }
            }
        }
        
        return ans;
    }
};

/**
 
 Time Limit Exceeded
 [86,27,76,72,44,86,51,72,77,85,88,43,1,11,98,7,17,8,13,6,17,88,100,22,7,88,6,11,63,24,8,72,33,79,13,49,54,36,39,27,31,25,23,76,40,36,8,60,59,80,98,6,8,58,55,73,20,7,59,17,100,1,52,97,68,27,84,75,6,28,55,30,4,90,33,97,10,11,90,16,72,31,31,95,59,46,35,59,91,60,6,88,55,2,10,48,84,56,44,73]
 
 62246
 
 
 Time Limit Exceeded
 [11,25,92,88,22,74,16,10,82,57,62,19,96,97,53,95,38,89,22,99,69,45,74,93,41,25,14,63,83,85,9,5,66,50,50,2,94,15,28,82,14,23,17,0,43,25,16,68,16,52,18,59,26,41,2,87,47,51,26,42,3,100,21,7,23,4,21,20,21,82,77,40,41,43,87,24,70,59,71,55,78,9,66,58,96,84,58,50,78,88,63,53,94,87,84,80,66,90,11,91]
 
 74227
 
 暴力枚举 DFS 超时
 */

int main(int argc, const char * argv[]) {
    
    Solution solve;
    
    
    vector<int> nums = {11,25,92,88,22,74,16,10,82,57,62,19,96,97,53,95,38,89,22,99,69,45,74,93,41,25,14,63,83,85,9,5,66,50,50,2,94,15,28,82,14,23,17,0,43,25,16,68,16,52,18,59,26,41,2,87,47,51,26,42,3,100,21,7,23,4,21,20,21,82,77,40,41,43,87,24,70,59,71,55,78,9,66,58,96,84,58,50,78,88,63,53,94,87,84,80,66,90,11,91};
    
    cout<<solve.triangleNumber(nums)<<endl;
    
    return 0;
}

