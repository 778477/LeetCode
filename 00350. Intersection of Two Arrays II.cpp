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
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>


using namespace std;

/**
 
 350. Intersection of Two Arrays II
 
 Given two arrays, write a function to compute their intersection.
 
 Example:
 Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 
 Note:
 Each element in the result should appear as many times as it shows in both arrays.
 The result can be in any order.
 Follow up:
 What if the given array is already sorted? How would you optimize your algorithm?
 What if nums1's size is small compared to nums2's size? Which algorithm is better?
 What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 
 */


/**
 
 Binary Search / Hash Table / Two Pointers / Sort
 
 61 / 61 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        unsigned i,j;
        i = j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                ++j,++i;
            } else{
                nums1[i] > nums2[j] ? ++j : ++i;
            }
        }
        
        return ans;
    }
};

int main(){
    
    
    return 0;
}
