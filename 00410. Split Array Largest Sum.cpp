//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
 
 
 410. Split Array Largest Sum
 
 Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
 
 Note:
 If n is the length of array, assume the following constraints are satisfied:
 
 1 ≤ n ≤ 1000
 1 ≤ m ≤ min(50, n)
 Examples:
 
 Input:
 nums = [7,2,5,10,8]
 m = 2
 
 Output:
 18
 
 Explanation:
 There are four ways to split nums into two subarrays.
 The best way is to split it into [7,2,5] and [10,8],
 where the largest sum among the two subarrays is only 18.
 Subscribe to see which companies asked this question.
 
 
 */

/*
 
 贪心策略:
 
 思考 划分一个数组划分成两个，最基础的情况：最佳情况一定是 左边的子数组之和 和 右边的子数组之和 相差最小。这样最大的数组之和也是最小的
 
 接着在这个基础上去接着划分。。
 
 Submission Details
 24 / 27 test cases passed.
 Status: Wrong Answer
 
 Input:
 [5334,6299,4199,9663,8945,3566,9509,3124,6026,6250,7475,5420,9201,9501,38,5897,4411,6638,9845,161,9563,8854,3731,5564,5331,4294,3275,1972,1521,2377,3701,6462,6778,187,9778,758,550,7510,6225,8691,3666,4622,9722,8011,7247,575,5431,4777,4032,8682,5888,8047,3562,9462,6501,7855,505,4675,6973,493,1374,3227,1244,7364,2298,3244,8627,5102,6375,8653,1820,3857,7195,7830,4461,7821,5037,2918,4279,2791,1500,9858,6915,5156,970,1471,5296,1688,578,7266,4182,1430,4985,5730,7941,3880,607,8776,1348,2974,1094,6733,5177,4975,5421,8190,8255,9112,8651,2797,335,8677,3754,893,1818,8479,5875,1695,8295,7993,7037,8546,7906,4102,7279,1407,2462,4425,2148,2925,3903,5447,5893,3534,3663,8307,8679,8474,1202,3474,2961,1149,7451,4279,7875,5692,6186,8109,7763,7798,2250,2969,7974,9781,7741,4914,5446,1861,8914,2544,5683,8952,6745,4870,1848,7887,6448,7873,128,3281,794,1965,7036,8094,1211,9450,6981,4244,2418,8610,8681,2402,2904,7712,3252,5029,3004,5526,6965,8866,2764,600,631,9075,2631,3411,2737,2328,652,494,6556,9391,4517,8934,8892,4561,9331,1386,4636,9627,5435,9272,110,413,9706,5470,5008,1706,7045,9648,7505,6968,7509,3120,7869,6776,6434,7994,5441,288,492,1617,3274,7019,5575,6664,6056,7069,1996,9581,3103,9266,2554,7471,4251,4320,4749,649,2617,3018,4332,415,2243,1924,69,5902,3602,2925,6542,345,4657,9034,8977,6799,8397,1187,3678,4921,6518,851,6941,6920,259,4503,2637,7438,3893,5042,8552,6661,5043,9555,9095,4123,142,1446,8047,6234,1199,8848,5656,1910,3430,2843,8043,9156,7838,2332,9634,2410,2958,3431,4270,1420,4227,7712,6648,1607,1575,3741,1493,7770,3018,5398,6215,8601,6244,7551,2587,2254,3607,1147,5184,9173,8680,8610,1597,1763,7914,3441,7006,1318,7044,7267,8206,9684,4814,9748,4497,2239]
 
 9
 
 Output:
 218624
 Expected:
 194890
 
 
 贪心划分反例：
 [2,1,1,2] 3
 
 贪心结果为 [2],[1],[1,2] = 3
 正确结果为 [2],[1,1],[2] = 2
 
 
 
 正解：
 
 答案区间: [left,right] 其中left是数组元素中的最大值，right是数组之和。
 如 [1，2，3，4，5] 答案区间是 [5,15]。
 
 二分枚举答案，并验证答案是否可行。若可行，则再逼近。
 
 如 贪心反例：
 答案区间是 [2,6].
 
 step 1. 二分枚举答案 (6+2)/2 = 4, 划分成3个数组的话， 数组之和最大值为4 能够满足。 接着逼近
 step 2. 二分枚举答案 (4+2)/2 = 3, 划分成3个数组的话， 数组之和最大值为3 能够满足。 接着逼近
 step 3. 二分枚举答案 (3+2)/2 = 2, 划分成3个数组的话， 数组之和最大值为2 能够满足。 接着逼近
 step 4. 枚举答案 = 区间左值(left)。 停止逼近
 
 答案是 2.
 
 */


/*
 
 
 27 / 27 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 
 */



class Solution {
public:
    bool cutable(const vector<int>& nums, int cuts, long long limit){
        long long acc = 0;
        for(int num : nums){
            if(num > limit) return false;
            if(acc + num <= limit){
                acc += num;
            } else{
                --cuts;
                acc = num;
                if(cuts < 0) return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int num : nums){
            right += num;
            left = (left > num ?:num);
        }
        
        while(left < right){
            long long mid = left + ((right - left)>>1);
            
            if(cutable(nums,m-1,mid)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return (int)left;
    }
};


int main(){
    
    Solution solve;
    vector<int> nums{1,2147483647};
    
    cout<<solve.splitArray(nums, 2)<<endl;
    
    return 0;
}
