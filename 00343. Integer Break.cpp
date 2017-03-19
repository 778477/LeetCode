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
 
 343. Integer Break
 
 Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
 
 For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 
 Note: You may assume that n is not less than 2 and not larger than 58.
 
 Hint:
 
 There is a simple O(n) solution to this problem.
 You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
 
 
 */


/**
 
 Dynamic Programming / Math
 
 
 
  3: 1,2               2
  4: 2,2               4
  5: 2,3               6
  6: 3,3               9
  7: 2,2,3            12
  8: 2,3,3            18
  9: 3,3,3            27
 10: 2,2,3,3          36
 11: 2,3,3,3          54
 12: 3,3,3,3          81
 13: 2,2,3,3,3       108
 14: 2,3,3,3,3       162
 15: 3,3,3,3,3
 
 
 50 / 50 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 */



class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        if(n == 5) return 6;
        if(n == 6) return 9;
        
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        dp[2] = 1,dp[3] = 2,dp[4] = 4,dp[5] = 6,dp[6] = 9;
        for(int i=7;i<=n;i++){
            dp[i] = 2 * dp[i-2] >  3 * dp[i-3] ? 2 * dp[i-2] : 3 * dp[i-3];
        }
        int ans = dp[n];
        free(dp);
        return ans;
    }
};


int main(){
    Solution solve;
    
    for(int i=3;i<59;i++){
        cout<<i<<" : "<<solve.integerBreak(i)<<endl;
    }
    
    return 0;
}
