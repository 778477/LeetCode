//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
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
 
 
 384. Shuffle an Array
 
 Total Accepted: 25090
 Total Submissions: 54431
 Difficulty: Medium
 Contributor: LeetCode
 Shuffle a set of numbers without duplicates.
 
 Example:
 
 // Init an array with set 1, 2, and 3.
 int[] nums = {1,2,3};
 Solution solution = new Solution(nums);
 
 // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 solution.shuffle();
 
 // Resets the array back to its original configuration [1,2,3].
 solution.reset();
 
 // Returns the random shuffling of array [1,2,3].
 solution.shuffle();
 
 
 */


/*
 
 使用 rand 随机取index，然后交换到末尾避免重新取用
 
 10 / 10 test cases passed.
 Status: Accepted
 Runtime: 236 ms
 
 */

class Solution {
public:
    Solution(vector<int> nums) {
        srand((unsigned)time(NULL));
        _original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> cp = _original;
        vector<int> sff(_original.size(),0);
        
        for(size_t i = 0; i<_original.size(); ++i){
            unsigned idx = rand()%(_original.size() - i);
            sff[i] = cp[idx];
            swap(cp[idx], cp[_original.size() - i - 1]);
        }
        
        return sff;
    }
    
private:
    vector<int> _original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main(){
    
    vector<int> nums{1,2,3};
    
    Solution *obj = new Solution(nums);
    
    vector<int> p = obj->reset();
    vector<int> p1 = obj->shuffle();
    vector<int> p2 = obj->reset();
    vector<int> p3 = obj->shuffle();
    
    
    
    return 0;
}
