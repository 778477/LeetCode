//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 398. Random Pick Index
 
 Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
 
 Note:
 The array size can be very large. Solution that uses too much extra space will not pass the judge.
 
 Example:
 
 int[] nums = new int[] {1,2,3,3,3};
 Solution solution = new Solution(nums);
 
 // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 solution.pick(3);
 
 // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
 solution.pick(1);
 */

/**
 
 13 / 13 test cases passed.
 Status: Accepted
 Runtime: 32 ms
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();


class Solution {
public:
    vector<int> cc;
    Solution(vector<int> nums) {
        cc = nums;
    }
    
    int pick(int target) {
        int ans = 0;
        int k = 1;
        
        for(auto i=0;i<cc.size();++i){
            if(cc[i] == target){
                if(rand() % k == 0){
                    ans = i;
                }
                ++k;
            }
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(){
    
    
    return 0;
}


