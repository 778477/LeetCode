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
 
 532. K-diff Pairs in an Array
 
 Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.
 
 Example 1:
 Input: [3, 1, 4, 1, 5], k = 2
 Output: 2
 Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
 Although we have two 1s in the input, we should only return the number of unique pairs.
 Example 2:
 Input:[1, 2, 3, 4, 5], k = 1
 Output: 4
 Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
 Example 3:
 Input: [1, 3, 1, 5, 4], k = 0
 Output: 1
 Explanation: There is one 0-diff pair in the array, (1, 1).
 Note:
 The pairs (i, j) and (j, i) count as the same pair.
 The length of the array won't exceed 10,000.
 All the integers in the given input belong to the range: [-1e7, 1e7].
 
 
 */

/*
 
 哈希 + 排序之后顺序枚举
 
 72 / 72 test cases passed.
 Status: Accepted
 Runtime: 52 ms
 
 
 */


class Solution {
    public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        if(nums.size() < 2) return 0;
        
        int ans = 0;
        unordered_map<int, int> table;
        
        for(int num : nums){
            ++table[num];
        }
        
        sort(nums.begin(), nums.end());
        
        int pre = 1e7+5;
        
        
        for(int num : nums){
            if(num == pre) continue;
            pre = num;
            int tmp = num + k;
            
            if(tmp == num){
                ans = table[tmp]>1 ? ans+1 : ans;
            } else {
                ans = table[tmp]>0 ? ans+1 : ans;
            }
        }
        
        return ans;
    }
};

int main(){
    
    Solution solve;
    
    vector<int> nums{1, 3, 1, 5, 4};
    cout<<solve.findPairs(nums, 0)<<endl;
    
    return 0;
}
