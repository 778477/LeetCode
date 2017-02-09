//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;


/**
 
 442. Find All Duplicates in an Array
 
 Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements that appear twice in this array.
 
 Could you do it without extra space and in O(n) runtime?
 
 Example:
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [2,3]
 
 */

/**
 
 28 / 28 test cases passed.
 Status: Accepted
 Runtime: 162 ms
 
 */

class Solution {
public:
    vector<int> findDouble(vector<int> nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int tmp = nums[i]-1,a;
            
            if(nums[i] > 0 && nums[tmp] <= 0){
                nums[tmp]--;
                nums[i] = 0;
                continue;
            }
            
            while(tmp > -1 && nums[tmp] >= 0){
                a = nums[tmp] - 1;
                nums[tmp] > 0 ? nums[tmp] = -1 : --nums[tmp];
                
                if(a < 0) break;
                tmp = a;
                if(nums[tmp] <= 0) --nums[tmp];
                nums[i] = 0;
            }
            
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] < -1){
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};

/**
 
 test case 1:
 3,3,5,6,6,7,1,2
 
 test case 2:
 4,3,2,7,8,2,3,1
 
 test case 3:
 2,2
 */

int main(){
    vector<int> nums({1,2,3,3,5,6,6,7});
    Solution solve;
    
    vector<int> ans = solve.findDouble(nums);
    
    for_each(ans.begin(), ans.end(), [](int num){
        cout<<num<<endl;
    });
}
