//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 796. Rotate String
 
 We are given two strings, A and B.
 
 A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.
 
 Example 1:
 Input: A = 'abcde', B = 'cdeab'
 Output: true
 
 Example 2:
 Input: A = 'abcde', B = 'abced'
 Output: false
 Note:
 
 A and B will have length at most 100.
 
 
 */


/**
 
 39 / 39 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 枚举 shift 次数，正反拼接对比，复杂度 = 1/2 * length(A)
 
 
 */


class Solution {
public:
    bool rotateString(string A, string B) {
        
        if(A.length() != B.length()) return false;
        
        for(size_t i = 1; i<=(A.length() + 1) / 2; ++i){
            if(B == A.substr(i, A.length() - i) + A.substr(0,i)  ||
               B == A.substr(A.length() - i,i) + A.substr(0,A.length() - i) ) return true;
        }
        
        return false;
        
    }
};


int main(){
    
    Solution solve;
    
    
    cout<<solve.rotateString("gcmbf", "fgcmb")<<endl;
    
    return 0;
}
