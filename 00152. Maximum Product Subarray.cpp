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
 
 
 152. Maximum Product Subarray
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 
 Subscribe to see which companies asked this question.
 
 */


/*
 
 
 183 / 183 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal,minVal,ans;
        int tmpMaxVal,tmpMinVal;
        ans = maxVal = minVal = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            tmpMaxVal = maxVal;
            tmpMinVal = minVal;
            maxVal = max(max(nums[i],tmpMaxVal*nums[i]),tmpMinVal*nums[i]);
            minVal = min(min(nums[i],tmpMinVal*nums[i]),tmpMaxVal*nums[i]);
            ans = max(maxVal,ans);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
