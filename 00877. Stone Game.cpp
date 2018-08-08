//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 
 877. Stone Game
 
 Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
 
 The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
 
 Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.
 
 Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
 
 
 
 Example 1:
 
 Input: [5,3,4,5]
 Output: true
 Explanation:
 Alex starts first, and can only take the first 5 or the last 5.
 Say he takes the first 5, so that the row becomes [3, 4, 5].
 If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
 If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
 This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 
 
 Note:
 
 2 <= piles.length <= 500
 piles.length is even.
 1 <= piles[i] <= 500
 sum(piles) is odd.
 
 */

/**
 
 46 / 46 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */





class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int sum = accumulate(piles.begin(), piles.end(), 0);
        size_t round = piles.size() / 2;
        
        vector<vector<int>> dp(round+1,vector<int>(2,0));
        dp[1][0] = piles[0];
        dp[1][1] = piles[piles.size() - 1];
        
        for(int i=2;i<=round;++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + piles[i - 1];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + piles[piles.size() - i];
        }
        
        return max(dp[round][0],dp[round][1]) > sum/2;
    }
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();


int main(){
    
    Solution solve;
    vector<int> piles{5,3,4,5,8,9};
    cout<<solve.stoneGame(piles)<<endl;
    
    return 0;
}


