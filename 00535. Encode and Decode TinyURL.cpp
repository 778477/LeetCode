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
#include <unordered_map>
#include <string>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 535. Encode and Decode TinyURL
 
 Note: This is a companion problem to the System Design problem: Design TinyURL.
 
 TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
 
 Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 
 Subscribe to see which companies asked this question.
 */


/**
 
 实现自增ID，维护ID和originUrl的映射关系
 
 739 / 739 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 */


class Solution {
private:
    unsigned COUNTID;
    map<string, unsigned> l2s;
    map<unsigned, string> s2l;
    const unsigned BASE = 62;
    const char charest[63] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
public:
    Solution(){
        COUNTID = 0;
    }
    
    string encode(string longUrl) {
        string ans = "http://tinyurl.com/";
        
        l2s[longUrl] = COUNTID;
        s2l[COUNTID] = longUrl;
        
        string path = base10ToBase62(COUNTID);
        string newPath = "";
        for(int i=0;i<6-path.length();i++){
            newPath+="0";
        }
        newPath += path;
        COUNTID++;
        return ans+newPath;
    }
    
    
    string decode(string shortUrl) {
        unsigned num = base62ToBase10(shortUrl.substr(shortUrl.length() - 6, 6));
        return s2l[num];
    }
    
    string base10ToBase62(unsigned num){
        string str = "";
        while (num) {
            str += charest[(num%BASE)];
            num = num/BASE;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    
    unsigned indexWithChar(const char ch){
        for(unsigned i = 0; i<62;i++){
            if(charest[i] == ch) return i;
        }
        
        return 0;
    }
    
    unsigned base62ToBase10(string str){
        unsigned num = 0;
        reverse(str.begin(), str.end());
        
        for(int i=0;i<str.length();i++){
            unsigned val = indexWithChar(str[i]);
            num = num + val * pow(BASE,i);
        }
        
        
        return num;
    }
};





int main(){
    Solution solve;
    string url = "https://leetcode.com/problems/design-tinyurl";
    string shortUrl = solve.encode(url);
    
    cout<<"encode :"<<shortUrl<<endl;
    cout<<"decode :"<<solve.decode(shortUrl)<<endl;
    return 0;
}
