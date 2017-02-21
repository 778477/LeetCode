//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>


#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 453. Minimum Moves to Equal Array Elements
 
 Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
 
 Example:
 
 Input:
 [1,2,3]
 
 Output:
 3
 
 Explanation:
 Only three moves are needed (remember each move increments two elements):
 
 [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 
 */

/**
 
 Math
 
 84 / 84 test cases passed.
 Status: Accepted
 Runtime: 56 ms
 
 */


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int minNum = nums[0];
        for(int num : nums){
            minNum = minNum > num ? num : minNum;
        }
        
        for(int num : nums){
            ans += (num - minNum);
        }
        
        return ans;
    }
};

int main(){
    return 0;
}



