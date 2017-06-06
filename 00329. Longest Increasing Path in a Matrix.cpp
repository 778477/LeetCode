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
 
 
 329. Longest Increasing Path in a Matrix
 
 Given an integer matrix, find the length of the longest increasing path.
 
 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 
 Example 1:
 
 nums = [
 [9,9,4],
 [6,6,8],
 [2,1,1]
 ]
 Return 4
 The longest increasing path is [1, 2, 6, 9].
 
 Example 2:
 
 nums = [
 [3,4,5],
 [3,2,6],
 [2,2,1]
 ]
 Return 4
 The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 
 Credits:
 Special thanks to @dietpepsi for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 
 */

/*
 
 记忆化搜索
 
 137 / 137 test cases passed.
 Status: Accepted
 Runtime: 46 ms
 
 */





class Solution {
public:
    const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(const vector<vector<int>>& matrix,vector<vector<int>>& dp,const int n,const int m,const int x,const int y){
        
        for (int i = 0; i < 4; i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            
            if(xx > -1 && xx < n && yy > -1 && yy < m && matrix[x][y] > matrix[xx][yy]){
                if(!dp[xx][yy]){
                    dp[xx][yy] = dfs(matrix,dp,n,m,xx,yy);
                }
                
                dp[x][y] = max(dp[x][y],1 + dp[xx][yy]);
            }
        }
        
        dp[x][y] = max(1,dp[x][y]);
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() < 1) return 0;
        
        int ans = 0;
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ans = max(ans, dfs(matrix,dp,n,m,i,j));
            }
        }
        
        return ans;
    }
};



int main(){
    
    vector<vector<int>> nums;
    vector<int> num1{1,2,3};
    vector<int> num2{4,5,6};
    vector<int> num3{7,8,9};
    
    nums.push_back(num1);
    nums.push_back(num2);
    nums.push_back(num3);
    
    Solution solve;
    
    cout<<solve.longestIncreasingPath(nums)<<endl;
    
    return 0;
}
