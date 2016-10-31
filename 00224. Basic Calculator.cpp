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
 
 224. Basic Calculator
 Total Accepted: 38082
 Total Submissions: 154258
 Difficulty: Hard
 Contributors: Admin
 Implement a basic calculator to evaluate a simple expression string.
 
 The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 
 You may assume that the given expression is always valid.
 
 Some examples:
 "1 + 1" = 2
 " 2-1 + 2 " = 3
 "(1+(4+5+2)-3)+(6+8)" = 23
 Note: Do not use the eval built-in library function.
 
 Subscribe to see which companies asked this question
 
 */


/*
 37 / 37 test cases passed.
 Status: Accepted
 Runtime: 56 ms
 */

class Solution {
public:
    int calculate(string s) {
        stack<int> vals;
        stack<char> ops;
        int tmp = 0;
        bool numBuf = false;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ') continue;
            else if(s[i] >= '0' && s[i] <= '9'){
                tmp = tmp*10 + (s[i] - '0');
                numBuf = true;
            } else{
                
                if(s[i] == '('){
                    ops.push(s[i]);
                    continue;
                } else if(numBuf){
                    vals.push(tmp);
                    tmp = 0;
                    numBuf = false;
                }
                
                if(s[i] == ')'){
                    while(ops.top() != '('){
                        int sec = vals.top();
                        vals.pop();
                        int fir = vals.top();
                        vals.pop();
                        
                        vals.push(calResult(fir, sec, ops.top()));
                        ops.pop();
                    }
                    ops.pop();
                    continue;
                }
                
                if(!ops.empty() && getOperatorLevel(ops.top()) >= getOperatorLevel(s[i])){
                    int sec = vals.top();
                    vals.pop();
                    int fir = vals.top();
                    vals.pop();
                    
                    vals.push(calResult(fir, sec, ops.top()));
                    ops.pop();
                }
                
                ops.push(s[i]);
            }
        }
        
        if(numBuf) vals.push(tmp);
        
        while(!ops.empty()){
            int sec = vals.top();
            vals.pop();
            int fir = vals.top();
            vals.pop();
            
            vals.push(calResult(fir, sec, ops.top()));
            ops.pop();
        }
        
        return vals.top();
    }
private:
    int calResult(const int fir,const int sec,const char op){
        int res = 0;
        switch (op) {
            case '-':
                res = fir - sec;
                break;
            case '+':
                res = fir + sec;
                break;
        }
        
        return res;
    }
    int getOperatorLevel(const char ch){
        if(ch == '-' || ch == '+') return 2;
        
        return 1;
    }
    bool isOperator(const char ch){
        return (ch==')'||ch=='('||ch=='-'||ch=='+');
    }
};


int main(){
    Solution *solve = new Solution();
    
    cout<<solve->calculate("(1)")<<endl;
    delete solve;
    
    return 0;
}
