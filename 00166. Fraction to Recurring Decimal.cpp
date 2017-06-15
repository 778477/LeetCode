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
 
 166. Fraction to Recurring Decimal
 
 Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 
 If the fractional part is repeating, enclose the repeating part in parentheses.
 
 For example,
 
 Given numerator = 1, denominator = 2, return "0.5".
 Given numerator = 2, denominator = 1, return "2".
 Given numerator = 2, denominator = 3, return "0.(6)".
 
 */


/*
 35 / 35 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 */


typedef long long int Int64;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string ans;
        
        if((numerator < 0) ^ (denominator < 0)) ans+='-'; // 处理 异号的情况
        Int64 n = numerator,d = denominator;
        n = abs(n), d = abs(d);
        ans+= to_string(n/d);
        Int64 p = n%d;
        if(!p) return ans;
        map<Int64, int> mp; // <p,index>
        ans+='.';
        while(p){
            if(mp.find(p)!=mp.end()){
                ans.insert(mp[p], 1,'(');
                ans+=')';
                return ans;
            }
            else{
                mp[p] = (int)ans.size();
                p*=10;
                ans+=to_string(p/d);
                p = p%d;
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
