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
using namespace std;

/**
 
 131. Palindrome Partitioning
 Total Accepted: 84825
 Total Submissions: 273872
 Difficulty: Medium
 Contributors: Admin
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return all possible palindrome partitioning of s.
 
 For example, given s = "aab",
 Return
 
 [
 ["aa","b"],
 ["a","a","b"]
 ]
 
 
 */

/**
 
 22 / 22 test cases passed.
 Status: Accepted
 Runtime: 9 ms
 Submitted: 0 minutes ago
 
 */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        
        dfs(s,tmp,ans);
        // judge self
        if(isPalindrome(s)){
            ans.push_back(vector<string>{s});
        }
        
        return ans;
        
    }
    
    void dfs(const string s,vector<string>& tmp,vector<vector<string>>& ans){
        for(int i=1;i<s.length();i++){
            if(!isPalindrome(s.substr(0,i))) continue;
            tmp.push_back(s.substr(0,i));
            string subStr = s.substr(i,s.length()-i);
            if(isPalindrome(subStr)){
                vector<string> V = tmp;
                V.push_back(subStr);
                ans.push_back(V);
            }
            dfs(subStr,tmp,ans);
            tmp.pop_back();
        }
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
    vector<vector<string>> ans = solve.partition("aabaa");
    
    for_each(ans.begin(), ans.end(), [](vector<string> strs){
        cout<<"[";
        for_each(strs.begin(), strs.end(), [](string str){
            cout<<"\""<<str<<"\",";
        });
        cout<<"]"<<endl;
    });
    
    
    return 0;
}
