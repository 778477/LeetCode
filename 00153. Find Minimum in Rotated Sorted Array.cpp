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
 
 153. Find Minimum in Rotated Sorted Array
 
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.
 
 */


/*
 
 
 146 / 146 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */


class Solution {
public:
    int findMin(vector<int> &num) {
        int ans = num[0];
        
        for(int i=1;i<num.size();i++)
            ans = min(ans,num[i]);
        return ans;
    }
};

int main(){
    
    return 0;
}
