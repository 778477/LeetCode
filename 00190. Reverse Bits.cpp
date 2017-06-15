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
 
 190. Reverse Bits
 
 Total Accepted: 102916
 Total Submissions: 348907
 Difficulty: Easy
 Contributor: LeetCode
 
 Reverse bits of a given 32 bits unsigned integer.
 
 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 
 Follow up:
 If this function is called many times, how would you optimize it?
 
 Related problem: Reverse Integer
 
 */


/*
 
 使用 bitset + stringStream + stoi 标准库实现
 
 Xcode依赖的stdlib版本 不支持 atoi
 
 600 / 600 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> x(n);
        stringstream strem;
        
        strem<<x;
        string s = strem.str();
        reverse(s.begin(), s.end());
        
        uint32_t ans = (uint32_t)stoul(s,0,2);
        return ans;
    }
};

int main(){
    
    
    Solution solve;
    
    cout<<(solve.reverseBits(43261596) == 964176192)<<endl;
    
    return 0;
}
