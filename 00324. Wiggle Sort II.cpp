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
 
 
 
 324. Wiggle Sort II
 
 Total Accepted: 28097
 Total Submissions: 109197
 Difficulty: Medium
 Contributor: LeetCode
 Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 
 Example:
 (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
 (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 
 Note:
 You may assume all input has valid answer.
 
 Follow Up:
 Can you do it in O(n) time and/or in-place with O(1) extra space?
 
 
 
 */


/*
 
 排序完，模拟构造答案
 
 44 / 44 test cases passed.
 Status: Accepted
 Runtime: 122 ms
 
 */


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unsigned long mid = (nums.size() + 1) >> 1;
        if(mid < 2) return;
        --mid;
        
        vector<int> ans;
        long long left = mid, right = nums.size() - 1;
        
        while(left > -1|| right > mid){
            if(left > -1){
                ans.push_back(nums[left]);
                --left;
            }
            
            if(right > mid){
                ans.push_back(nums[right]);
                --right;
            }
        }
        
        nums = ans;
    }
};


int main(){
    
    vector<int> nums{3,4,1,4};
    Solution solve;
    
    solve.wiggleSort(nums);
    
    for(int num : nums){
        cout<<num<<endl;
    }
    
    return 0;
}
