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
 
 278. First Bad Version
 
 You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 
 Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 
 You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 Show Tags
 Show Similar Problems
 
 
 */

/*
 
 模拟 二分查找
 
 21 / 21 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 
 */


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1,right = n;
    int mid = 1;
    
    while(left <= right){
        mid = (right - left)/2 + left;
        
        if(!isBadVersion(mid)){
            left = mid + 1;
        } else {
            if(mid == 1 || !isBadVersion(mid-1)) return mid;
            else {
                right = mid - 1;
            }
        }
    }
    
    return mid;
}

int main(){
    
    
    return 0;
}
