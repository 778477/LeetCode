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
 
 168. Excel Sheet Column Title
 
 Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 
 For example:
 
 1 -> A
 2 -> B
 3 -> C
 ...
 26 -> Z
 27 -> AA
 28 -> AB
 
 
 */

/*
 
 模拟 26进制
 
 18 / 18 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */


class Solution {
    public:
    string convertToTitle(int n) {
        string str = "";
        
        while(n){
            str += ('A' + (n-1)%26);
            n = (n-1)/26;
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
};

int main(){
    
    Solution solve;
    for(int i = 1; i<40;i++){
        cout<<solve.convertToTitle(i)<<endl;
    }
    
    return 0;
}
