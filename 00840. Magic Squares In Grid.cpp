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
 840. Magic Squares In Grid
 
 Difficulty: Easy
 A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
 
 Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
 
 
 
 Example 1:
 
 Input: 
 [[4,3,8,4],
 [9,5,1,9],
 [2,7,6,2]]
 Output: 1
 Explanation:
 The following subgrid is a 3 x 3 magic square:
 438
 951
 276
 
 while this one is not:
 384
 519
 762
 
 In total, there is only one magic square inside the given grid.
 Note:
 
 1 <= grid.length <= 10
 1 <= grid[0].length <= 10
 0 <= grid[i][j] <= 15
 
 */


/**
 
 
 87 / 87 test cases passed.
 Status: Accepted
 Runtime: 5 ms
 
 */

class Solution {
public:
    
    bool isValid(int x,int y,const vector<vector<int>>& grid){
        
        vector<bool> vis(10,false);
        int xx = x+3;
        int yy = y+3;
        
        int sum = 0;
        
        // get sum
        for(int i=x;i<xx;++i){
            sum += grid[i][y];
        }
        
        
        int tmp = 0;
        for(int i=x;i<xx;++i){
            tmp = 0;
            for(int j=y;j<yy;++j){
                
                if(grid[i][j] > 9 || grid[i][j] < 1) return false;
                
                if(vis[grid[i][j]]) return false;
                
                tmp += grid[i][j];
                vis[grid[i][j]] = true;
            }
            
            if(tmp != sum) return false;
        }
        
        
        for(int i=y;i<yy;++i){
            tmp = 0;
            for(int j=x;j<xx;++j){
                tmp += grid[j][i];
            }
            if(tmp != sum) return false;
        }
        
        
        int diagonals1 = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        int diagonals2 = grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2];
        
        
        return (diagonals1 == sum) && (diagonals2 == sum);
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        
        int n = (int)grid.size();
        if(n < 1) return ans;
        int m = (int)grid[0].size();
        
        
        for(int i = 0; i <= n - 3; ++i){
            for(int j=0; j <= m - 3; ++j){
                if(isValid(i,j,grid)){
                    ++ans;
                }
            }
        }
        
        
        return ans;
    }
};

int main(){
    
    Solution solve;
    
    vector<int> row1{4,3,8,4};
    vector<int> row2{9,5,1,9};
    vector<int> row3{2,7,6,2};
    
    vector<vector<int>> grid;
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    
    cout<<solve.numMagicSquaresInside(grid)<<endl;
    
    
    return 0;
}
