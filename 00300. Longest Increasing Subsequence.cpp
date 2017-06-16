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
 
 
 300. Longest Increasing Subsequence
 
 Total Accepted: 76875
 Total Submissions: 201945
 Difficulty: Medium
 Contributor: LeetCode
 Given an unsorted array of integers, find the length of longest increasing subsequence.
 
 For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 
 Your algorithm should run in O(n2) complexity.
 
 Follow up: Could you improve it to O(n log n) time complexity?
 
 Credits:
 Special thanks to @pbrother for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 
 */


/*
 
 经典LIS问题，使用low_bounder代替二分查找
 
 24 / 24 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> lis;
        vector<int>::iterator low;
        
        for(int num : nums){
            low = lower_bound(lis.begin(), lis.end(), num);
            long idx = low - lis.begin();
            if(idx >= lis.size()){
                lis.push_back(num);
            } else {
                lis[idx] = num;
            }
        }
        
        
        return (int)lis.size();
    }
};


int main(){
    
    
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    Solution solve;
    
    cout<<solve.lengthOfLIS(nums)<<endl;
    
    return 0;
}
