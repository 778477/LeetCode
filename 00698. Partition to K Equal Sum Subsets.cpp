//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy on 2017/9/19.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 698. Partition to K Equal Sum Subsets
 
 Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
 
 Example 1:
 Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 Output: True
 Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 Note:
 
 1 <= k <= len(nums) <= 16.
 0 < nums[i] < 10000.
 
 */

/**
 
 147 / 147 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 fix #416. Partition Equal Subset Sum
 fix #698. Partition to K Equal Sum Subsets
 
 暴力枚举组合+剪枝
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        return canPartitionKSubsets(nums, 2);
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum/k)*k != sum) return false;
        
        vector<int> buckets(k,0);
        sort(nums.begin(), nums.end(), greater<int>());
        return nums.size() >= k && canPartitionToBuckets(nums, 0, buckets, sum/k);
    }
    
    bool canPartitionToBuckets(const vector<int> nums,int idx,vector<int>& buckets,int target){
        if(idx == nums.size()){
            for(int bVal : buckets){
                if(bVal != target) return false;
            }
            return true;
        }
        
        int pushVal = nums[idx];
        for(auto i = 0; i < buckets.size(); ++i){
            auto& bVal = buckets[i];
            
            if(bVal + pushVal > target) continue;
            if(i != 0 && buckets[i-1] == bVal) continue; // 剪枝优化 122ms -> 6ms。 意义是之前尝试过 bVal+pushVal 不成功的话，这样的组合就不必再试了
            bVal += pushVal;
            if(canPartitionToBuckets(nums, idx+1, buckets, target)) return true;
            bVal -= pushVal;
        }
        
        return false;
    }
};

// [4, 3, 2, 3, 5, 2, 1], k = 4

int main(int argc, const char * argv[]) {
    
    Solution solve;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    
    cout<<solve.canPartitionKSubsets(nums,4)<<endl;
    
    
    return 0;
}

