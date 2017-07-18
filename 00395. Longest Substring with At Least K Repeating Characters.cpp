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

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/**
 
 
 395. Longest Substring with At Least K Repeating Characters
 
 Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
 
 Example 1:
 
 Input:
 s = "aaabb", k = 3
 
 Output:
 3
 
 The longest substring is "aaa", as 'a' is repeated 3 times.
 Example 2:
 
 Input:
 s = "ababbc", k = 2
 
 Output:
 5
 
 The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 
 
 */


/**
 
 28 / 28 test cases passed.
 Status: Accepted
 Runtime: 168 ms
 
 */

class Solution {
    public:
    int longestSubstring(string s, int k) {
        if(k == 0) return (int)s.size();
        if(s.size() == 0 || s.size() < k) return 0;
        
        int table[26] = {0};
        
        for (char c : s){
            ++table[c - 'a'];
        }
        
        int idx = 0;
        while(idx < s.size() && table[s[idx] - 'a'] >= k) ++idx;
        if(idx == s.size()) return (int)s.size();
        
        
        int left = longestSubstring(s.substr(0,idx), k);
        int right = longestSubstring(s.substr(idx+1), k);
        
        return max(left, right);
    }
};


int main(){
    Solution solve;
    cout<<solve.longestSubstring("ababbc", 2)<<endl;
    return 0;
}

