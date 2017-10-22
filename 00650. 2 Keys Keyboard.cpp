//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy on 2017/9/19.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 650. 2 Keys Keyboard
 
 Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
 
 Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
 Paste: You can paste the characters which are copied last time.
 Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
 
 Example 1:
 Input: 3
 Output: 3
 Explanation:
 Intitally, we have one character 'A'.
 In step 1, we use Copy All operation.
 In step 2, we use Paste operation to get 'AA'.
 In step 3, we use Paste operation to get 'AAA'.
 
 Note:
 The n will be in the range [1, 1000].
 */

/**
 
 126 / 126 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        
        int *dp = (int *)malloc(sizeof(int) * (n+5));
        memset(dp, 0, sizeof(int) * (n+5));
        
        for(int i=2;i<=n;++i) dp[i] = dp[1]+i;
        
        for(int i=2;i<=n;++i){
            for(int j=i+i;j<=n;j+=i){
                dp[j] = min(dp[j], dp[i] + j/i);
            }
        }
        
        ans = dp[n];
        free(dp);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solve;
    cout<<solve.minSteps(100)<<endl;
    
    
    return 0;
}

