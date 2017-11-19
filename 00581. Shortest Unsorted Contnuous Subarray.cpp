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
 
 
 581. Shortest Unsorted Continuous Subarray
 
 Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
 
 You need to find the shortest such subarray and output its length.
 
 Example 1:
 Input: [2, 6, 4, 8, 10, 9, 15]
 Output: 5
 Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 Note:
 Then length of the input array is in range [1, 10,000].
 The input array may contain duplicates, so ascending order here means <=.
 
 
 */


/**
 
 
 307 / 307 test cases passed.
 Status: Accepted
 Runtime: 49 ms
 
 */



class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans = (int)nums.size();
        
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        
        int i = 0;
        
        while(i < nums.size() && tmp[i] == nums[i]){
            ++i;
        }
        
        int j = ans - 1;
        
        while(j > -1 && tmp[j] == nums[j]){
            --j;
        }
        
        if(j > i){
            ans = j - i + 1;
        } else {
            ans = 0;
        }
        
        return ans;
    }
};


int main(){
    
    Solution solve;
    vector<int> nums = {2, 3, 4, 8, 10, 9, 8};
    
    cout<<solve.findUnsortedSubarray(nums)<<endl;
    
    return 0;
}
