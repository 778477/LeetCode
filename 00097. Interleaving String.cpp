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
 
 97. Interleaving String
 
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.
 
 */


/**
 
 Dynamic Programming / String
 
 101 / 101 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> valid(s1.length()+1,vector<bool>(s2.length()+1,false));
        
        if(s1.length() + s2.length() != s3.length()) return false;
        
        for( auto i = 0; i <= s1.length(); i++){
            for( auto j = 0; j <= s2.length(); j++){
                
                if(i == 0 && j == 0){
                    valid[i][j] = true;
                } else if(i == 0){
                    valid[i][j] = valid[i][j-1] ? (s2[j-1] == s3[i+j-1]) : false;
                } else if(j == 0){
                    valid[i][j] = valid[i-1][j] ? (s1[i-1] == s3[i+j-1]) : false;
                } else{
                    valid[i][j] = (valid[i-1][j] && s1[i-1] == s3[i+j-1]) || (valid[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
                
            }
        }
        
        return valid[s1.length()][s2.length()];
    }
};


int main(){
    Solution solve;
    
    cout<<solve.isInterleave("a", "", "a")<<endl;
    cout<<solve.isInterleave("aabcc", "dbbca", "aadbbcbcac")<<endl;
    cout<<solve.isInterleave("aabcc", "dbbca", "aadbbbaccc")<<endl;
    
    return 0;
}
