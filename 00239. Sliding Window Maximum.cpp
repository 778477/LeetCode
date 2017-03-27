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
 
 239. Sliding Window Maximum
 
 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 
 For example,
 Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 
 Window position                Max
 ---------------               -----
 [1  3  -1] -3  5  3  6  7      3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 Therefore, return the max sliding window as [3,3,5,5,6,7].
 
 Note:
 You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 
 */


/**
 
 18 / 18 test cases passed.
 Status: Accepted
 Runtime: 86 ms
 
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> window;
        
        if(k == 1) return nums;
        
        for(int i=0;i<k;i++){
            vector<int>::iterator it = lower_bound(window.begin(), window.end(), nums[i]);
            if(it == window.end()){
                window.push_back(nums[i]);
            } else{
                window.insert(it, nums[i]);
            }
        }
        
        ans.push_back(window.back());
        
        for(int i=k;i<nums.size();i++){
            window.erase(lower_bound(window.begin(), window.end(), nums[i-k]));
            vector<int>::iterator it = lower_bound(window.begin(), window.end(), nums[i]);
            if(it == window.end()){
                window.push_back(nums[i]);
            } else{
                window.insert(it, nums[i]);
            }
            ans.push_back(window.back());
        }
        
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    
    vector<int> ans = solve.maxSlidingWindow(nums, 3);
    
    for(int num : ans){
        cout<<num<<endl;
    }
    
    
    return 0;
}
