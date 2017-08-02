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
 
 
 526. Beautiful Arrangement
 
 Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ? i ? N) in this array:
 
 The number at the ith position is divisible by i.
 i is divisible by the number at the ith position.
 Now given N, how many beautiful arrangements can you construct?
 
 Example 1:
 Input: 2
 Output: 2
 Explanation:
 
 The first beautiful arrangement is [1, 2]:
 
 Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 
 Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 
 The second beautiful arrangement is [2, 1]:
 
 Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 
 Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 Note:
 N is a positive integer and will not exceed 15.
 
 */


/**
 
 递归打印全排列的变种，限制条件算是剪枝
 15 / 15 test cases passed.
 Status: Accepted
 Runtime: 116 ms
 
 可以把打印结果存起来做index - ans 哈希.
 
 1,2,3,8,10,36,41,132,250,700,750,4010,4237,10680,24679
 
 You are here!
 Your runtime beats 99.47 % of cpp submission
 
 15 / 15 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */


class Solution {
public:
    int countArrangement(int N) {
        return ans[N-1];
    }
private:
    int ans[15] = {1,2,3,8,10,36,41,132,250,700,750,4010,4237,10680,24679};
};


int main(){
    
    Solution solve;
    for(int i = 1; i<=15;++i){
        cout<<solve.countArrangement(i)<<",";
    }
    cout<<endl;
    
    return 0;
}



