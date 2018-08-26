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
 
 892. Surface Area of 3D Shapes
 
 On a N * N grid, we place some 1 * 1 * 1 cubes.
 
 Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
 
 Return the total surface area of the resulting shapes.
 
 
 
 Example 1:
 
 Input: [[2]]
 Output: 10
 Example 2:
 
 Input: [[1,2],[3,4]]
 Output: 34
 Example 3:
 
 Input: [[1,0],[0,2]]
 Output: 16
 Example 4:
 
 Input: [[1,1,1],[1,0,1],[1,1,1]]
 Output: 32
 Example 5:
 
 Input: [[2,2,2],[2,1,2],[2,2,2]]
 Output: 46
 
 
 Note:
 
 1 <= N <= 50
 0 <= grid[i][j] <= 50
 */

/**
 
 90 / 90 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(auto i=0; i<grid.size(); ++i){
            for(auto j=0; j<grid.size(); ++j){
                ans = ans + (grid[i][j] > 0 ? 1 : 0);
            }
        }
        
        const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for(auto i=0;i<grid.size();++i){
            for (auto j=0; j<grid[i].size(); ++j) {
                int tmp = 0;
                for(int k=0;k<4;++k){
                    auto ii = i + dir[k][0];
                    auto jj = j + dir[k][1];
                    if(ii>-1&&ii<grid.size()&&jj>-1&&jj<grid.size()&&grid[ii][jj]>grid[i][j]){
                        tmp += grid[ii][jj] - grid[i][j];
                    }
                }
                ans = ans + tmp + (grid[i][j] > 0 ? 1 : 0);
            }
        }
        
        
        for(auto i=0;i<grid.size(); ++i){
            ans = ans + grid[i].front() + grid[i].back();
        }
        
        for(auto i=0;i<grid.size();++i){
            ans = ans + grid[0][i] + grid[grid.size() - 1][i];
        }
        return ans;
    }
};

/**
 {{1,2},{3,4}} => 34
 {{2,2,2},{2,1,2},{2,2,2}} => 46
 */

int main(){
    
    Solution solve;
    vector<vector<int>> grid = {{2,2,2},{2,1,2},{2,2,2}};
    cout<<solve.surfaceArea(grid)<<endl;
    return 0;
}


