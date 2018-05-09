//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 829. Consecutive Numbers Sum
 
 Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?
 
 Example 1:
 
 Input: 5
 Output: 2
 Explanation: 5 = 5 = 2 + 3
 Example 2:
 
 Input: 9
 Output: 3
 Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
 Example 3:
 
 Input: 15
 Output: 4
 Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 Note: 1 <= N <= 10 ^ 9.
 
 
 */


/**
 
 170 / 170 test cases passed.
 Status: Accepted
 Runtime: 10 ms
 
 小学数学题
 
 */

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 1,sum = 0;
        
        for(int i=2; 1; ++i){
            sum = sum + i - 1;
            
            if(sum >= N) break;
            
            if((N-sum) % i == 0){
                ++ans;
            }
        }
        
        return ans;
    }
};


int main(){
    
    
    Solution solve;
    cout<<solve.consecutiveNumbersSum(15)<<endl;
    
    return 0;
}
