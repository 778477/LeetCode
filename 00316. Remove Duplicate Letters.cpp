//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 316. Remove Duplicate Letters
 
 Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
 
 Example 1:
 
 Input: "bcabc"
 Output: "abc"
 Example 2:
 
 Input: "cbacdcbc"
 Output: "acdb"
 
 */

/**
 
 286 / 286 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        unordered_map<char, unsigned> counter;
        unordered_map<char, bool> viser;
        
        for(auto c : s){
            counter[c]++;
            viser[c] = false;
        }
        
        
        for(auto c : s){
            counter[c]--;
            if(viser[c]) continue;
            
            while(!ans.empty() && ans.back() > c && counter[ans.back()] > 0){
                viser[ans.back()] = false;
                ans.pop_back();
            }
            
            viser[c] = true;
            ans += c;
        }
        
        
        return ans;
    }
};


int main(){
    
    Solution solve;
    cout<<solve.removeDuplicateLetters("abcb")<<endl;
    
    return 0;
}


