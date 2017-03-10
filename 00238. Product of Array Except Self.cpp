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
 
 238. Product of Array Except Self
 
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 
 Solve it without division and in O(n).
 
 For example, given [1,2,3,4], return [24,12,8,6].
 
 Follow up:
 Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 
 */


/**
 
 Array
 
 17 / 17 test cases passed.
 Status: Accepted
 Runtime: 56 ms
 
 */


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> leftProduct(nums.size(),1);
        vector<int> rightProduct(nums.size(),1);
        
        for(auto i=1;i<nums.size();i++) leftProduct[i] = leftProduct[i-1] * nums[i-1];
        for(int  i=(int)nums.size()-2;i>=0;--i) rightProduct[i] = rightProduct[i+1] * nums[i+1];
        
        for(auto i = 0; i < nums.size() ; i++) ans[i] = leftProduct[i] * rightProduct[i];
        
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> nums{1,2,3,4};
    vector<int> ans = solve.productExceptSelf(nums);
    
    for( int num : ans ){
        cout<<num<<endl;
    }
    
    return 0;
}
