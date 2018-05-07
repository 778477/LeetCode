//
//  main.cpp
//  whiteBorad-leetcode
//
//  Created by 郭妙友 on 2018/3/30.
//  Copyright © 2018年 郭妙友. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 
 583. Delete Operation for Two Strings
 
 Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.
 
 Example 1:
 Input: "sea", "eat"
 Output: 2
 Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
 Note:
 The length of given words won't exceed 500.
 Characters in given words can only be lower-case letters.
 
 
 */

/**
 
 1307 / 1307 test cases passed.
 Status: Accepted
 Runtime: 43 ms
 
 
 解题思路：
 LCS，最长公共子序列
 
 注意到删除多余的字符后，留下的字符串正好是 LCS
 所以 minDistance(w1,w2) = w1.length + w2.length - 2*LCS(w1,w2);
 
 */
class Solution {
public:
    int LCS(const string word1,const string word2){
        vector<vector<int>> dp(word1.length() + 1,vector<int>(word2.length() + 1,0));
        for(size_t i = 1; i <= word1.length(); ++i){
            for(size_t j = 1; j <= word2.length(); ++j){
                dp[i][j] = max(dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 1 : 0),max(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[word1.length()][word2.length()];
    }
    
    int minDistance(string word1, string word2) {
        return (int)(word1.length() + word2.length() - 2 *LCS(word1, word2));
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solve;
    cout<<solve.minDistance("abcdaf", "acbcf")<<endl;
    
    return 0;
}

