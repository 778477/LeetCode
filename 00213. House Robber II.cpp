//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 213. House Robber II
 
 Note: This is an extension of House Robber.
 
 After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 
 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 
 Credits:
 Special thanks to @Freezen for adding this problem and creating all test cases.
 
 
 
 
 
 */


/**
 
 74 / 74 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */

class Solution {
public:
    int robber(vector<int>& nums, int s,int e){
        int cur = 0,pre = 0;
        for(int i=s;i<=e;++i){
            int temp = max(pre + nums[i],cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if(n < 2) return n ? nums[0] : 0;
        
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
};

int main(){
    
    
    vector<int> nums{0,0};
    
    Solution solve;
    cout<<solve.rob(nums)<<endl;
    
    return 0;
}
