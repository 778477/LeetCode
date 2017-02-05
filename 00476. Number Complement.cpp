//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

/**
 
 476. Number Complement
 
 Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 
 Note:
 The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 You could assume no leading zero bit in the integer’s binary representation.
 Example 1:
 Input: 5
 Output: 2
 Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 Example 2:
 Input: 1
 Output: 0
 Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
 
 */


/**
 
 149 / 149 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */

class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int bit = 0;
        int tmp = 0;
        
        while(num){
            tmp = !(num&0x01);
            ans = ans + tmp * pow(2,bit);
            num >>= 1;
            bit++;
        }
        
        
        return ans;
    }
};
