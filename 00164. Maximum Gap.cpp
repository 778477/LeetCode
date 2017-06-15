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
 
 164. Maximum Gap
 
 Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 
 Try to solve it in linear time/space.
 
 Return 0 if the array contains less than 2 elements.
 
 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 
 */


/*
 18 / 18 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 */



class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size() < 2) return 0;
        sort(num.begin(), num.end(), [&](const int a, const int b){
            return a < b;
        });
        int ans = 0;
        int now = num[0];
        for_each(num.begin(), num.end(), [&](int number){
            ans = max(ans,number-now);
            now = number;
        });
        return ans;
    }
};


int main(){
    
    return 0;
}
