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
 
 561. Array Partition I
 
 Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
 
 Example 1:
 Input: [1,4,3,2]
 
 Output: 4
 Explanation: n is 2, and the maximum sum of pairs is 4.
 Note:
 n is a positive integer, which is in the range of [1, 10000].
 All the integers in the array will be in the range of [-10000, 10000].
 Subscribe to see which companies asked this question.
 
 */

/*
 
 贪心策略： 分组的时候，取最大数和次最大数在一起。这样让组的"最小值"最大
 
 81 / 81 test cases passed.
 Status: Accepted
 Runtime: 82 ms
 
 
 */


class Solution {
    public:
    int arrayPairSum(vector<int>& nums) {
        int ans = 0;
        
        sort(nums.begin(), nums.end(), less<int>());
        
        for(auto i = 0; i < nums.size(); i+=2){
            ans += nums[i];
        }
        
        return ans;
    }
};

int main(){
    vector<int> nums{2,3,1,4};
    
    Solution solve;
    cout<<solve.arrayPairSum(nums)<<endl;
    
    return 0;
}
