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
 
 
 334. Increasing Triplet Subsequence
 
 Total Accepted: 39493
 Total Submissions: 101683
 Difficulty: Medium
 Contributor: LeetCode
 Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 
 Formally the function should:
 Return true if there exists i, j, k
 such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 Your algorithm should run in O(n) time complexity and O(1) space complexity.
 
 Examples:
 Given [1, 2, 3, 4, 5],
 return true.
 
 Given [5, 4, 3, 2, 1],
 return false.
 
 
 */


/*
 
 最长递增子序列的变种，先求最长递增子序列长度再比较是否大于3(Triplet)
 
 61 / 61 test cases passed.
 Status: Accepted
 Runtime: 9 ms
 
 */


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        return lengthOfLIS(nums) >= 3;
    }
    
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
    
    
    
    return 0;
}
