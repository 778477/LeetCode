//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 462. Minimum Moves to Equal Array Elements II
 
 Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
 
 You may assume the array's length is at most 10,000.
 
 Example:
 
 Input:
 [1,2,3]
 
 Output:
 2
 
 Explanation:
 Only two moves are needed (remember each move increments or decrements one element):
 
 [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 
 
 */


/**
 
 中位数
 
 29 / 29 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 
 */




class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        
        if(nums.size() & 0x01){
            int mid = nums[nums.size()>>1];
            
            for(int num : nums){
                ans += abs(num - mid);
            }
        } else{
            int mid = nums[nums.size() >> 1];
            int mid1 = nums[(nums.size() >> 1 ) - 1];
            int tmp(0);
            for(int num : nums){
                ans += abs(num - mid);
                tmp += abs(num - mid1);
            }
            
            ans = tmp < ans ? tmp : ans;
        }
        
        return ans;
    }
};

int main(){
    return 0;
}
