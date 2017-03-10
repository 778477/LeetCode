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
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 371. Sum of Two Integers
 
 Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 
 Example:
 Given a = 1 and b = 2, return 3.
 
 Credits:
 Special thanks to @fujiaozhu for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 
 */


/**
 
 Bit Manipulation
 
 13 / 13 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a^b,(a&b)<<1);
    }
};


int main(){
    
    
    
    return 0;
}
