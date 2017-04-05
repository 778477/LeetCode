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
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 322. Coin Change
 
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)
 
 Example 2:
 coins = [2], amount = 3
 return -1.
 
 Note:
 You may assume that you have an infinite number of each kind of coin.
 
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 
 */


/**
 
 182 / 182 test cases passed.
 Status: Accepted
 Runtime: 29 ms
 
 */


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        
        int *dp = (int *)malloc(sizeof(int) * (amount+1));
        memset(dp, -1, sizeof(int) * (amount + 1));
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int coin : coins){
            if(coin > amount) continue;
            dp[coin] = 1;
        }
        
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i < coins[j]) break;
                
                if(dp[i - coins[j]] != -1 && (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)){
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        
        ans = dp[amount];
        free(dp);
        return ans;
    }
};
int main(){
    Solution solve;
    vector<int> coins{474,83,404,3};
    
    cout<<solve.coinChange(coins, 264)<<endl;
    
    return 0;
}
