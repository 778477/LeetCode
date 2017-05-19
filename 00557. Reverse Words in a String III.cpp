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
 
 557. Reverse Words in a String III
 
 Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 
 Example 1:
 Input: "Let's take LeetCode contest"
 Output: "s'teL ekat edoCteeL tsetnoc"
 Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 
 
 */

/*
 
 30 / 30 test cases passed.
 Status: Accepted
 Runtime: 23 ms
 
 */


class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        string tmp;
        
        for (char ch : s){
            if(ch == ' '){
                if(tmp.length() > 0){
                    reverse(tmp.begin(), tmp.end());
                    ans+=tmp;
                    ans+=ch;
                    tmp.clear();
                }
            } else {
                tmp+=ch;
            }
        }
        
        if(tmp.length() > 0){
            reverse(tmp.begin(), tmp.end());
            ans+=tmp;
        }
        
        return ans;
    }
};

int main(){
    
    Solution solve;
    string str = "Let's take LeetCode contest";
    cout<<solve.reverseWords(str)<<endl;
    
    return 0;
}
