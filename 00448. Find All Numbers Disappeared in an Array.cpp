//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

/**
 
 448. Find All Numbers Disappeared in an Array
 
 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements of [1, n] inclusive that do not appear in this array.
 
 Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 
 Example:
 
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [5,6]
 
 */


/**
 
 34 / 34 test cases passed.
 Status: Accepted
 Runtime: 143 ms
 
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int tmp = nums[i] - 1;
            while(nums[tmp]){
                int a = tmp;
                tmp = nums[tmp] - 1;
                nums[a] = 0;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> nums({1,2,3,3,4,6});
    vector<int> ans = solve.findDisappearedNumbers(nums);
    
    
    for_each(ans.begin(), ans.end(), [](int num){
        cout<<num<<endl;
    });
    
    return 0;
}
