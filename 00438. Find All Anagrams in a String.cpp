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

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/**
 
 438. Find All Anagrams in a String
 
 Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 
 Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 
 The order of output does not matter.
 
 Example 1:
 
 Input:
 s: "cbaebabacd" p: "abc"
 
 Output:
 [0, 6]
 
 Explanation:
 The substring with start index = 0 is "cba", which is an anagram of "abc".
 The substring with start index = 6 is "bac", which is an anagram of "abc".
 Example 2:
 
 Input:
 s: "abab" p: "ab"
 
 Output:
 [0, 1, 2]
 
 Explanation:
 The substring with start index = 0 is "ab", which is an anagram of "ab".
 The substring with start index = 1 is "ba", which is an anagram of "ab".
 The substring with start index = 2 is "ab", which is an anagram of "ab".
 
 */

/**
 
 
 36 / 36 test cases passed.
 Status: Accepted
 Runtime: 29 ms
 
 */




class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length() < p.length()) return ans;
        
        vector<int> pTable(26,0);
        vector<int> sTable(26,0);
        
        for(char c : p){
            ++pTable[c - 'a'];
        }
        
        for(size_t i=0;i<p.length();++i){
            ++sTable[s[i] - 'a'];
        }
        
        unsigned more = 0;
        unsigned less = 0;
        
        for(size_t i = 0; i < 26; ++i){
            if(sTable[i] > pTable[i]) more += (sTable[i] - pTable[i]);
            else if(sTable[i] < pTable[i]) less += (pTable[i] - sTable[i]);
        }
        
        if(more + less == 0) ans.push_back(0);
        
        unsigned long len = s.length() - p.length();
        for(unsigned i = 1; i <= len; ++i){
            
            unsigned pop = s[i-1]-'a';
            unsigned push = s[i+p.length()-1] - 'a';
            
            if(sTable[pop] > pTable[pop]){
                --more;
            } else {
                ++less;
            }
            --sTable[pop];
            ++sTable[push];
            if(sTable[push] > pTable[push]){
                ++more;
            } else {
                --less;
            }
            
            
            if(more + less == 0) ans.push_back(i);
            
        }
        
        return ans;
    }
};



int main(){
    
    Solution solve;
    
    vector<int> ans = solve.findAnagrams("cbaebabacd", "a");
    
    for_each(ans.begin(), ans.end(), [](const int num){
        cout<<num<<endl;
    });
    
    return 0;
}
