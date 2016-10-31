//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

/*
 227. Basic Calculator II
 Total Accepted: 33773
 Total Submissions: 123011
 Difficulty: Medium
 Contributors: Admin
 Implement a basic calculator to evaluate a simple expression string.
 
 The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 
 You may assume that the given expression is always valid.
 
 Some examples:
 "3+2*2" = 7
 " 3/2 " = 1
 " 3+5 / 2 " = 5
 Note: Do not use the eval built-in library function.
 
 
 */


// 表达式求值，逆波兰式

/*
 109 / 109 test cases passed.
 Status: Accepted
 Runtime: 42 ms
 */


class Solution {
public:
    int calculate(string s) {
        
        stack<int> vals;
        stack<char> ops;
        int tmp = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                tmp = tmp*10 + (s[i]-'0');
            }
            
            if(i == s.length() - 1 || isOperator(s[i])){
                vals.push(tmp);
                tmp = 0;
                
                while(!ops.empty() && getOperatorLevel(ops.top()) >= getOperatorLevel(s[i])){
                    int sec = vals.top();
                    vals.pop();
                    int fir = vals.top();
                    vals.pop();
                    
                    vals.push(calResult(fir,sec,ops.top()));
                    ops.pop();
                }
                
                if(isOperator(s[i])) ops.push(s[i]);
            }
        }
        
        
        stack<int> reVals;
        stack<char> reOps;
        
        while(!vals.empty()){
            reVals.push(vals.top());
            vals.pop();
        }
        
        while (!ops.empty()) {
            reOps.push(ops.top());
            ops.pop();
        }
        
        while(!reOps.empty()){
            int fir = reVals.top();
            reVals.pop();
            int sec = reVals.top();
            reVals.pop();
            
            reVals.push(calResult(fir,sec,reOps.top()));
            reOps.pop();
        }
        
        return reVals.top();
    }
private:
    bool isOperator(const char op){
        return (op=='+'||op=='-'||op=='*'||op=='/');
    }
    int calResult(const int fir,const int sec,const char op){
        int res = 0;
        switch (op) {
            case '+':
                res = fir + sec;
                break;
            case '-':
                res = fir - sec;
                break;
            case '*':
                res = fir * sec;
                break;
            case '/':
                res = fir / sec;
                break;
        }
        
        return res;
    }
    int getOperatorLevel(const char op){
        int level = 0;
        switch (op) {
            case '+':
                level = 1;
                break;
            case '-':
                level = 1;
                break;
            case '*':
                level = 2;
                break;
            case '/':
                level = 2;
                break;
        }
        return level;
    }
};


int main(){
    Solution *solve = new Solution();
    
    cout<<solve->calculate("282-1*2*13-30-2*2*2/2-95/5*2+55+804+3024")<<endl;
    delete solve;
    
    return 0;
}
