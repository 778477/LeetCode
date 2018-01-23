
//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 769. Max Chunks To Make Sorted
 
 Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.
 
 What is the most number of chunks we could have made?
 
 Example 1:
 
 Input: arr = [4,3,2,1,0]
 Output: 1
 Explanation:
 Splitting into two or more chunks will not return the required result.
 For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
 Example 2:
 
 Input: arr = [1,0,2,3,4]
 Output: 4
 Explanation:
 We can split into two chunks, such as [1, 0], [2, 3, 4].
 However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
 Note:
 
 arr will have length in range [1, 10].
 arr[i] will be a permutation of [0, 1, ..., arr.length - 1]
 
 
 
 
 */

/**
 
 52 / 52 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.empty()) return 0;
        int ans = 0;
        int tmpMax = -1;
        for(int i=0;i<arr.size();++i){
            tmpMax = tmpMax > arr[i] ? tmpMax : arr[i];
            if(i >= tmpMax) ++ans;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    vector<int> nums{0,1,3,2,4};
    cout<<solve.maxChunksToSorted(nums)<<endl;
    
    return 0;
}
