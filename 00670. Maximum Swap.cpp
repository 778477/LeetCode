//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;



/**
 
 
 670. Maximum Swap
 
 Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
 
 Example 1:
 Input: 2736
 Output: 7236
 Explanation: Swap the number 2 and the number 7.
 Example 2:
 Input: 9973
 Output: 9973
 Explanation: No swap.
 Note:
 The given number is in the range [0, 108]
 
 
 */


/**
 
 贪心 构造最大数，按数字排序即可。 转换成string方便遍历/排序
 
 111 / 111 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */

class Solution {
    public:
    int maximumSwap(int num) {
        
        string oriStr = to_string(num);
        string srtStr = to_string(num);
        sort(srtStr.begin(), srtStr.end(),greater<char>());
        if(srtStr == oriStr) return num;
        
        size_t idx = 0,endIdx = oriStr.size() - 1;
        while(srtStr[idx] == oriStr[idx]) ++idx;
        while (oriStr[endIdx] != srtStr[idx]) --endIdx;
        swap(oriStr[idx], oriStr[endIdx]);
        
        return stoi(oriStr);
    }
};

int main(){
    Solution solve;
    
    cout<<solve.maximumSwap(000)<<endl;
    cout<<solve.maximumSwap(001)<<endl;
    cout<<solve.maximumSwap(5534)<<endl;
    return 0;
}

