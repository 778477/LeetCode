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

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;



/**
 
 659. Split Array into Consecutive Subsequences
 
 You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
 
 Example 1:
 Input: [1,2,3,3,4,5]
 Output: True
 Explanation:
 You can split them into two consecutive subsequences :
 1, 2, 3
 3, 4, 5
 Example 2:
 Input: [1,2,3,3,4,4,5,5]
 Output: True
 Explanation:
 You can split them into two consecutive subsequences :
 1, 2, 3, 4, 5
 3, 4, 5
 Example 3:
 Input: [1,2,3,4,4,5]
 Output: False
 Note:
 The length of the input is in range of [1, 10000]
 
 */


/**
 
 纯模拟，需要考虑一种情况：当有多个可以插入的数组的时候，优先选择长度最短的
 
 180 / 180 test cases passed.
 Status: Accepted
 Runtime: 1499 ms
 
 */

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<vector<int> *> subSeqs;
        
        bool creatNewSeq = true;
        for(int num : nums){
            
            long long idx = -1;
            
            for(unsigned i=0; i<subSeqs.size(); ++i){
                if(subSeqs[i]->back() + 1 == num){
                    creatNewSeq = false;
                    idx = (idx == -1 ? i : (subSeqs[idx]->size() < subSeqs[i]->size() ? idx : i));
                }
            }
            
            if(idx == -1){
                vector<int> *newSeq = new vector<int>();
                newSeq->push_back(num);
                subSeqs.push_back(newSeq);
            } else {
                subSeqs[idx]->push_back(num);
            }
        }
        
        
        for(vector<int> *seq : subSeqs){
            if(seq->size() < 3) return false;
        }
        
        return true;
    }
};

/**
 
 test case #1:
 
 [1,2,3,3,4,5]
 Output:
 false
 
 */

int main(){
    
    Solution solve;
    //    vector<int> nums{1,2,3,3,4,4,5,5};
    vector<int> nums{1,2,3,3,4,5};
    cout<<solve.isPossible(nums)<<endl;
    
    return 0;
}


