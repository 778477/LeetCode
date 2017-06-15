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
 
 171. Excel Sheet Column Number
 
 Related to question Excel Sheet Column Title
 
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 
 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 
 */


/*
 1000 / 1000 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 */


int titleToNumber(char* s) {
    int ans = 0;
    int len = (int)strlen(s);
    
    for(int i = 0;i<len;i++){
        int tmp = s[i]-'A' + 1;
        ans += (pow(26,len-i-1)*tmp);
    }
    
    return ans;
}
int main(){
    
    return 0;
}
