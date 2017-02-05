//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 
 461. Hamming Distance
 
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 
 Given two integers x and y, calculate the Hamming distance.
 
 Note:
 0 ≤ x, y < 2^31.
 
 Example:
 
 Input: x = 1, y = 4
 
 Output: 2
 
 Explanation:
 1   (0 0 0 1)
 4   (0 1 0 0)
 ↑   ↑
 
 The above arrows point to positions where the corresponding bits are different.
 
 
 */


/**
 
 149 / 149 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        
        while(x || y){
            if( (x&0x01) ^ (y&0x01) ) ans++;
            
            x>>=1;
            y>>=1;
        }
        
        return ans;
    }
};
