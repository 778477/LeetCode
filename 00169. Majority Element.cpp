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
 
 169. Majority Element
 
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.
 
 */


/*
 44 / 44 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 */


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int result = 0;
        for_each(nums.begin(),nums.end(),[&](const int num){
            if(!count){
                result = num;
                count++;
            }
            else if(num != result){
                count--;
            }
            else{
                count++;
            }
        });
        return result;
    }
};

int main(){
    
    return 0;
}
