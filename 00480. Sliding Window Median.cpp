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
 
 480. Sliding Window Median
 
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 
 Examples:
 [2,3,4] , the median is 3
 
 [2,3], the median is (2 + 3) / 2 = 2.5
 
 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
 
 For example,
 Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 
 Window position                Median
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 
 Note:
 You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 
 Subscribe to see which companies asked this question.
 
 */


/**
 
 注意 总数为偶数求中位数时 小心int相加总值爆掉 int最大值
 
 42 / 42 test cases passed.
 Status: Accepted
 Runtime: 66 ms
 
 */


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        
        if(k < 2) {
            for(int num : nums){
                ans.push_back(num*1.0);
            }
            return ans;
        }
        
        vector<int> window;
        
        for(auto i=0;i<k;i++){
            vector<int>::iterator it = lower_bound(window.begin(), window.end(), nums[i]);
            if (it == window.end()) {
                window.push_back(nums[i]);
            } else {
                window.insert(it, nums[i]);
            }
        }
        
        if (window.size() & 0x01) {
            ans.push_back(window[window.size()>>1]*1.0);
        } else {
            ans.push_back((window[window.size()>>1]*1.0/2 + window[(window.size()>>1) - 1]*1.0/2));
        }
        
        for(auto i=k;i<nums.size();i++){
            window.erase(lower_bound(window.begin(), window.end(), nums[i-k]));
            
            vector<int>::iterator it = lower_bound(window.begin(), window.end(), nums[i]);
            if (it == window.end()) {
                window.push_back(nums[i]);
            } else {
                window.insert(it, nums[i]);
            }
            
            if (window.size() & 0x01) {
                ans.push_back(window[window.size()>>1]*1.0);
            } else {
                ans.push_back((window[window.size()>>1]*1.0/2 + window[(window.size()>>1) - 1]*1.0/2));
            }
            
        }
        
        return ans;
    }
};
int main(){
    Solution solve;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    
    vector<double> ans = solve.medianSlidingWindow(nums, 3);
    
    for(double num : ans){
        cout<<num<<endl;
    }
    
    return 0;
}
