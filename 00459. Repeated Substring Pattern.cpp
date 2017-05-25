//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
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
 
 459. Repeated Substring Pattern
 
 Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 
 Example 1:
 Input: "abab"
 
 Output: True
 
 Explanation: It's the substring "ab" twice.
 Example 2:
 Input: "aba"
 
 Output: False
 Example 3:
 Input: "abcabcabcabc"
 
 Output: True
 
 Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 
 */

/*
 
 107 / 107 test cases passed.
 Status: Accepted
 Runtime: 49 ms
 
 */

typedef unsigned long ul;
class Solution {
public:
    vector<ul> factorization(unsigned long n){
        vector<ul> f;
        if(n < 2) return f;
        
        f.push_back(1);
        
        for(ul i = 2; i<= sqrt(n); i++){
            if(n % i == 0){
                f.push_back(i);
                if(n/i != i){
                    f.push_back(n/i);
                }
            }
        }
        
        sort(f.begin(), f.end());
        
        return f;
    }
    
    bool check(string s,ul n){
        
        string subStr = s.substr(0,n);
        
        for(ul i = 0;i<s.length();i+=n){
            if(subStr != s.substr(i,n)) return false;
        }
        
        return true;
    }
    
    bool repeatedSubstringPattern(string s) {
        
        vector<ul> f = factorization(s.length());
        
        for(ul l : f){
            if(check(s,l)) return true;
        }
        
        return false;
    }
};
int main(){
    Solution solve;
    
    cout<<solve.repeatedSubstringPattern("")<<endl;
    
    
    return 0;
}
