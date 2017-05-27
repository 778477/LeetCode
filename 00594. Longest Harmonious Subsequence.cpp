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
 
 594. Longest Harmonious Subsequence
 
 We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
 
 Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
 
 Example 1:
 Input: [1,3,2,2,5,2,3,7]
 Output: 5
 Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 Note: The length of the input array will not exceed 20,000.
 
 */

/*
 
 201 / 201 test cases passed.
 Status: Accepted
 Runtime: 146 ms
 
 */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        int ans = 0;
        map<int,int> table;
        
        for (int num : nums){
            ++table[num];
        }
        
        for (pair<int, int> p : table){
            if(table[p.first - 1] > 0){
                ans = ans > p.second + table[p.first - 1] ? ans : p.second + table[p.first - 1];
            }
        }
        
        return ans;
        
    }
};


int main(){
    vector<int> v{1,3,2,2,5,2,3,7};
    vector<int> v1{1,1,1,1};
    Solution solve;
    
    cout<<solve.findLHS(v1)<<endl;
    
    return 0;
}
