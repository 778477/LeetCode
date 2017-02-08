//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 
 496. Next Greater Element I
 You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
 
 The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
 
 Example 1:
 Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 Output: [-1,3,-1]
 Explanation:
 For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
 For number 1 in the first array, the next greater number for it in the second array is 3.
 For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 Example 2:
 Input: nums1 = [2,4], nums2 = [1,2,3,4].
 Output: [3,-1]
 Explanation:
 For number 2 in the first array, the next greater number for it in the second array is 3.
 For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 
 */


/**
 
 17 / 17 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        bool finded = false;
        for(int i = 0; i < findNums.size(); i++){
            finded = false;
            for(int j=0; j < nums.size(); j++){
                if(finded && nums[j] > findNums[i]){
                    ans.push_back(nums[j]);
                    break;
                }
                
                if(nums[j] == findNums[i]){
                    finded = true;
                }
            }
            if(ans.size() != i+1) ans.push_back(-1);
        }
        
        return ans;
    }
};


int main(){
    Solution solve;
    vector<int> findNames({4,1,2});
    vector<int> nums({1,3,4,2});
    
    solve.nextGreaterElement(findNames, nums);
    
    return 0;
}
