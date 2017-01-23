//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/1/23.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

/**
 
 132. Palindrome Partitioning II
 Total Accepted: 63826
 Total Submissions: 271820
 Difficulty: Hard
 Contributors: Admin
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return the minimum cuts needed for a palindrome partitioning of s.
 
 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 
 Subscribe to see which companies asked this question
 
 */

/**
 
 25 / 29 test cases passed.
 Status: Time Limit Exceeded
 
 "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi"
 */

struct palindromeNode {
    string _str;
    int _step;
    
    palindromeNode(string str,int s):_str(str),_step(s){}
};

class Solution {
public:
    int minCut(string s) {
        if(!s.length()) return -1;
        if(isPalindrome(s)) return 0;
        
        queue<palindromeNode> Q;
        Q.push(palindromeNode(s, 0));
        
        while(!Q.empty()){
            palindromeNode now = Q.front();
            Q.pop();
            for(int i=1;i<now._str.length();i++){
                if(!isPalindrome(now._str.substr(0,i))) continue;
                string suffStr = now._str.substr(i,now._str.length() - i);
                if(isPalindrome(suffStr)) return now._step + 1;
                Q.push(palindromeNode(suffStr,now._step+1));
            }
        }
        
        
        return (int)s.length()-1;
    }
    
    
    bool isPalindrome(const string str){
        if(!str.length()) return false;
        
        size_t i = 0, j = str.length() - 1;
        
        while(i < j){
            if(str[i] != str[j]) return false;
            i++,j--;
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    cout<<solve.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi")<<endl;
    
    return 0;
}
