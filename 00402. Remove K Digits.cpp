//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 402. Remove K Digits
 
 Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
 
 Note:
 The length of num is less than 10002 and will be ≥ k.
 The given num does not contain any leading zero.
 Example 1:
 
 Input: num = "1432219", k = 3
 Output: "1219"
 Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 Example 2:
 
 Input: num = "10200", k = 1
 Output: "200"
 Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 Example 3:
 
 Input: num = "10", k = 2
 Output: "0"
 Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 
 
 
 
 */

/**
 
 贪心 + 模拟
 
 33 / 33 test cases passed.
 Status: Accepted
 Runtime: 179 ms
 
 33 / 33 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k == 0) return num;
        
        while(k > 0 && !num.empty()){
            unsigned idx = 0;
            
            while(idx + 1 <= num.size() && num[idx] <= num[idx + 1]){
                ++idx;
            }
            num.erase(num.begin() + idx);
            while(num.size() >= 1 && num[0] == '0') num.erase(num.begin());
            --k;
        }
        
        return num.empty() ? "0" : num;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solve;
    cout<<solve.removeKdigits("112", 1)<<endl;
    return 0;
}

