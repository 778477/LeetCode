//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;



/**
 https://leetcode.com/problems/knight-dialer/
 
 A chess knight can move as indicated in the chess diagram below:
 
 .
 
 
 
 This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.
 
 Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.
 
 How many distinct numbers can you dial in this manner?
 
 Since the answer may be large, output the answer modulo 10^9 + 7.
 
 
 
 Example 1:
 
 Input: 1
 Output: 10
 Example 2:
 
 Input: 2
 Output: 20
 Example 3:
 
 Input: 3
 Output: 46
 
 
 Note:
 
 1 <= N <= 5000
 
 */

/**
 
 120 / 120 test cases passed.
 Status: Accepted
 Runtime: 28 ms
 
 */




// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();


class Solution {
    public:
    int knightDialer(int N) {
        if(N == 1) return 10;
        const int INF = 1e9 + 7;
        int ans = 0;
        
        vector<vector<int>> buck = {
            {4,6},
            {6,8},
            {7,9},
            {4,8},
            {0,3,9},
            {},
            {0,1,7},
            {2,6},
            {1,3},
            {2,4}};
        
        vector<vector<int>> dp(10,vector<int>(N+1, 0));
        
        for(int i=0;i<10;++i) dp[i][1] = 1;
        
        for(int j = 2; j <= N; ++j){
            for(int i = 0; i < 10; i++){
                if(i == 5) continue;
                
                int tmp = 0;
                for(int k = 0; k<buck[i].size(); ++k){
                    tmp += dp[buck[i][k]][j-1];
                    tmp %= INF;
                }
                
                dp[i][j] = tmp;
            }
        }
        
        ans = 0;
        for(int i=0;i<10;++i){
            if(i != 5){
                ans += dp[i][N];
                ans %= INF;
            }
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    
    cout<<solve.knightDialer(890)<<endl;
    
    return 0;
}

