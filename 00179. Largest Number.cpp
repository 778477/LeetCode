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
 
 179. Largest Number
 
 Total Accepted: 72921
 Total Submissions: 327563
 Difficulty: Medium
 Contributor: LeetCode
 
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.
 
 */


/*
 221 / 221 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 */


class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> strs;
        for_each(num.begin(), num.end(), [&](int i){
            strs.push_back(to_string(i));
        });
        
        sort(strs.begin(), strs.end(), [&](const string& a,const string& b){
            return (a+b) > (b+a);
        });
        string ans = "";
        for_each(strs.begin(), strs.end(), [&](string obj){
            if(obj == "0" && ans == "") return ;
            ans += obj;
            
        });
        return ans == "" ? "0" : ans;
    }
};

int main(){
    
    return 0;
}
