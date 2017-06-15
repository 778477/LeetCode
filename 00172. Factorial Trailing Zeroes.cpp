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
 
 172. Factorial Trailing Zeroes
 
 Given an integer n, return the number of trailing zeroes in n!.
 
 Note: Your solution should be in logarithmic time complexity.
 
 */


/*
 502 / 502 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 */


int trailingZeroes(int n) {
    int ans = 0;
    while(n){
        ans += (n / 5);
        n/=5;
    }
    return ans;
}


int main(){
    
    return 0;
}
