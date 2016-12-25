//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

/*
 477. Total Hamming Distance
 Total Accepted: 2276
 Total Submissions: 5456
 Difficulty: Medium
 Contributors: kevin.xinzhao@gmail.com
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 
 Now your job is to find the total Hamming distance between all pairs of the given numbers.
 
 Example:
 Input: 4, 14, 2
 
 Output: 6
 
 Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
 showing the four bits relevant in this case). So the answer will be:
 HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
 Note:
 Elements of the given array are in the range of 0 to 10^9
 Length of the array will not exceed 10^4.
 Subscribe to see which companies asked this question
 
 Hide Tags Bit Manipulation
 Hide Similar Problems (E) Hamming Distance
 
 **/

/*
 Accepted	89 ms	cpp
 **/
class Solution {
    public:
    int hammingDistance(int x, int y) {
        int dis = 0;
        
        int tmp = x^y;
        while(tmp){
            (tmp&0x1) ? dis++ : dis;
            tmp = tmp >> 1;
        }
        
        return dis;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        
        for (int i=0; i < 32; i++){
            int cnt = 0;
            for(int j=0;j<nums.size();j++){
                cnt += ((nums[j]>>i) & 0x01);
            }
            
            total += cnt * (nums.size() - cnt);
        }
        
        return total;
    }
};
