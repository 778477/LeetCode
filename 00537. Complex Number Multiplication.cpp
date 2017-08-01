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
 
 
 537. Complex Number Multiplication
 
 Given two strings representing two complex numbers.
 
 You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
 
 Example 1:
 Input: "1+1i", "1+1i"
 Output: "0+2i"
 Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
 Example 2:
 Input: "1+-1i", "1+-1i"
 Output: "0+-2i"
 Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 Note:
 
 The input strings will not have extra blank.
 The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
 
 */



/**
 
 模拟题
 
 55 / 55 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */

class Solution {
public:
    void format(const string& str, int *a, int *b){
        string buf = "";
        for(char ch : str){
            if(ch == '+'){
                *a = stoi(buf);
                buf.clear();
            } else if(ch == 'i'){
                *b = stoi(buf);
            } else{
                buf+=ch;
            }
        }
    }
    
    string complexNumberMultiply(string a, string b) {
        
        int a1,a2,b1,b2;
        a1 = a2 = b1 = b2 = 0;
        
        format(a,&a1,&b1);
        format(b,&a2,&b2);
        
        stringstream stream;
        stream<<(a1*a2 - b1*b2)<<"+"<<(a1*b2 + a2*b1)<<"i";
        return stream.str();
    }
};



int main(){
    Solution solve;
    cout<<solve.complexNumberMultiply("1+1i", "1+1i")<<endl;
}



