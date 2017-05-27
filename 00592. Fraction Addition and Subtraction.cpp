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
 
 592. Fraction Addition and Subtraction
 
 Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.
 
 Example 1:
 Input:"-1/2+1/2"
 Output: "0/1"
 
 Example 2:
 Input:"-1/2+1/2+1/3"
 Output: "1/3"
 
 Example 3:
 Input:"1/3-1/2"
 Output: "-1/6"
 
 Example 4:
 Input:"5/3+1/3"
 Output: "2/1"
 
 Note:
 The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
 Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
 
 The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
 
 The number of given fractions will be in the range [1,10].
 
 The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
 
 */

/*
 
 辗转相除法求最大公约数,(只能处理自然数，不能处理负数)
 
 105 / 105 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */

class Solution {
public:
    
    int gcd(int a,int b){
        if(a < b){
            a = a + b, b = a - b, a = a - b;
        }
        return a%b ? gcd(b,a%b) : b;
    }
    
    
    
    string fractionAddition(string expression) {
        
        vector<fraction> fs;
        
        unsigned long idx = 0;
        
        for(auto i = 0; i < expression.length(); i++){
            
            if((expression[i] == '-' || expression[i] == '+') && i != idx){
                fs.push_back(fraction(expression.substr(idx,i-idx)));
                idx = i;
            }
            
            if(expression.length() > 1 && i == expression.length() - 1){
                fs.push_back(fraction(expression.substr(idx)));
            }
        }
        
        
        if(fs.size() < 1) return "invalid input!";
        
        fraction fir = fs.front();
        
        for(auto i = 1; i < fs.size(); i++){
            int g = gcd(fir.denominator, fs[i].denominator);
            int c = fir.denominator * fs[i].denominator / g;
            
            fir.numerator = (fir.numerator * (c/fir.denominator)) + (fs[i].numerator * (c/fs[i].denominator));
            fir.denominator = c;
        }
        
        if(fir.numerator % fir.denominator == 0){
            fir.numerator = fir.numerator / fir.denominator;
            fir.denominator = 1;
        } else {
            int c = gcd(abs(fir.numerator),abs(fir.denominator));
            while(c != 1){
                fir.numerator /= c;
                fir.denominator /= c;
                c = gcd(abs(fir.numerator),abs(fir.denominator));
            }
        }
        
        string ans = to_string(fir.numerator);
        ans += '/';
        ans += to_string(fir.denominator);
        return ans;
    }
private:
    struct fraction{
        int numerator,denominator;
        
        fraction(string fractionStr){
            const char seg = '/';
            numerator = denominator = 0;
            bool flag = false;
            
            int *tmp = &numerator;
            
            for(char c : fractionStr){
                if(c == seg){
                    tmp = &denominator;
                } else if(c == '-'){
                    flag = true;
                } else if(c == '+'){
                    flag = false;
                } else {
                    *tmp = (*tmp)*10 + (c - '0');
                }
            }
            
            if(flag) numerator *=-1;
        }
    };
};


int main(){
    Solution solve;
    
    cout<<"-1/2+1/2 = "<<solve.fractionAddition("-1/2+1/2")<<endl;
    cout<<"-1/2+1/2+1/3 = "<<solve.fractionAddition("-1/2+1/2+1/3")<<endl;
    cout<<"1/3-1/2 = "<<solve.fractionAddition("1/3-1/2")<<endl;
    cout<<"5/3+1/3 = "<<solve.fractionAddition("5/3+1/3")<<endl;
    cout<<"-5/1+8/1+1/1 = "<<solve.fractionAddition("-5/1+8/1+1/1")<<endl;
    
    return 0;
}
