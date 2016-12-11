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
 
 474. Ones and Zeroes
 User Accepted: 144
 User Tried: 359
 Total Accepted: 180
 Total Submissions: 974
 Difficulty: Medium
 In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
 
 For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.
 
 Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 
 Note:
 The given numbers of 0s and 1s will both not exceed 100
 The size of given string array won't exceed 600.
 Example 1:
 Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 Output: 4
 
 Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
 Example 2:
 Input: Array = {"10", "0", "1"}, m = 1, n = 1
 Output: 2
 
 Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
 
 */



/*
 
 
 60 / 60 test cases passed.
 Status: Accepted
 Runtime: 436 ms
 
 
 */



class Solution {
    public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(101,vector<int>(101,0));
        
        int ans = 0;
        
        for_each(strs.begin(), strs.end(), [&](const string str){
            int zore = 0, one = 0;
            
            for(size_t i = 0;i<str.length();i++){
                if(str[i] == '0') zore++;
                else one++;
            }
            
            for(int i=m; i>=zore;i--){
                for(int j=n; j>= one; j--){
                    dp[i][j] = dp[i][j] > dp[i-zore][j-one] + 1 ? dp[i][j] : dp[i-zore][j-one] + 1;
                    
                    ans = ans > dp[i][j] ? ans : dp[i][j];
                }
            }
            
        });
        
        return ans;
    }
};

int main(){
    
    
    return 0;
}

