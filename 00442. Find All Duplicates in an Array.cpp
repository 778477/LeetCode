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
 Runtime: 209 ms
 
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        int index = 0;
        while(index < nums.size()){
            if(nums[index] != nums[nums[index] - 1]){
                swap(nums[index], nums[nums[index] - 1]);
            } else{
                index++;
            }
        }
        
        for(index = 0; index < nums.size(); index++){
            if(nums[index] != index+1){
                ans.push_back(nums[index]);
            }
        }
        
        
        return ans;
    }
};

int main(){
    Solution solve;
    vector<int> nums({4,3,2,7,8,2,3,1});
    vector<int> ans = solve.findDuplicates(nums);
    
    
    for_each(ans.begin(), ans.end(), [](int num){
        cout<<num<<endl;
    });
    
    return 0;
}
