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
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 503. Next Greater Element II
 
 Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
 
 Example 1:
 Input: [1,2,1]
 Output: [2,-1,2]
 Explanation: The first 1's next greater number is 2;
 The number 2 can't find next greater number;
 The second 1's next greater number needs to search circularly, which is also 2.
 Note: The length of given array won't exceed 10000.
 
 
 
 
 */


/**
 
 224 / 224 test cases passed.
 Status: Accepted
 Runtime: 223 ms
 
 */


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<bool> vis(nums.size(),false);
        
        for(auto i = 0; i < nums.size();i++){
            int tmp = -1;
            for(auto j=i+1;j<nums.size();j++){
                if(nums[j] > nums[i]){
                    tmp = nums[j];
                    vis[i] = true;
                    break;
                }
            }
            ans[i] = tmp;
        }
        
        for(auto i = (int)nums.size() - 1; i > -1; --i){
            if(vis[i]) continue;
            int tmp = -1;
            for(auto j = 0; j<i; j++){
                if(nums[j] > nums[i]){
                    tmp = nums[j];
                    break;
                } else if(vis[j] && ans[j] > nums[i]){
                    tmp = ans[j];
                    break;
                }
            }
            ans[i] = tmp;
        }
        
        return ans;
    }
};

// [1,8,-1,-100,-1,222,1111111,-111111]
int main(){
    
    Solution solve;
    vector<int> nums({1,8,-1,-100,-1,222,1111111,-111111});
    
    vector<int> ans = solve.nextGreaterElements(nums);
    
    for_each(ans.begin(), ans.end(), [](const int num){
        cout<<num<<endl;
    });
    
    return 0;
}
