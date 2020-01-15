
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

/**
 *
 *
1293. Shortest Path in a Grid with Obstacles Elimination

Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input:
grid =
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]],
k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 

Example 2:

Input:
grid =
[[0,1,1],
 [1,1,1],
 [1,0,0]],
k = 1
Output: -1
Explanation:
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0
 **/

// Runtime: 4 ms, faster than 97.25% of C++ online submissions for Shortest Path in a Grid with Obstacles Elimination.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Shortest Path in a Grid with Obstacles Elimination.
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int n = grid.size(), m = grid[0].size();
        if(k >= n+m-2) return n+m-2;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(n*m+1,0x3fff3fff)));
        queue<tuple<int,int,int>> q;// point, step, k
        q.push({0,0,k});
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            if(get<0>(now) == n*m-1) return get<1>(now);
            for(auto& i : dir){
                int xx = (get<0>(now) / m) + i[0];
                int yy = (get<0>(now) % m) + i[1];
                if(xx>-1&&xx<n&&yy>-1&&yy<m){
                    int curK = get<2>(now);
                    curK -= grid[xx][yy];
                    if(curK < 0) continue;
                    if(vis[xx][yy][curK] <= get<1>(now) + 1) continue;
                    vis[xx][yy][curK] = get<1>(now) + 1;
                    q.push({xx*m+yy, get<1>(now) + 1, curK});
                }
            }
        }
        return -1;
    }
};

// [[0,0,1,0,0,0,0,1,0,1,1,0,0,1,1],
// [0,0,0,1,1,0,0,1,1,0,1,0,0,0,1],
// [1,1,0,0,0,0,0,1,0,1,0,0,1,0,0],
// [1,0,1,1,1,1,0,0,1,1,0,1,0,0,1],
// [1,0,0,0,1,1,0,1,1,0,0,1,1,1,1],
// [0,0,0,1,1,1,0,1,1,0,0,1,1,1,1],
// [0,0,0,1,0,1,0,0,0,0,1,1,0,1,1],
// [1,0,0,1,1,1,1,1,1,0,0,0,1,1,0],
// [0,0,1,0,0,1,1,1,1,1,0,1,0,0,0],
// [0,0,0,1,1,0,0,1,1,1,1,1,1,0,0],
// [0,0,0,0,1,1,1,0,0,1,1,1,0,1,0]]
// 27
int main(){
    Solution solve;
    vector<vector<int>> grid;
    grid.push_back({0,0,1,0,0,0,0,1,0,1,1,0,0,1,1});
    grid.push_back({0,0,0,1,1,0,0,1,1,0,1,0,0,0,1});
    grid.push_back({1,1,0,0,0,0,0,1,0,1,0,0,1,0,0});
    grid.push_back({1,0,1,1,1,1,0,0,1,1,0,1,0,0,1});
    grid.push_back({1,0,0,0,1,1,0,1,1,0,0,1,1,1,1});
    grid.push_back({0,0,0,1,1,1,0,1,1,0,0,1,1,1,1});
    grid.push_back({0,0,0,1,0,1,0,0,0,0,1,1,0,1,1});
    grid.push_back({1,0,0,1,1,1,1,1,1,0,0,0,1,1,0});
    grid.push_back({0,0,1,0,0,1,1,1,1,1,0,1,0,0,0});
    grid.push_back({0,0,0,1,1,0,0,1,1,1,1,1,1,0,0});
    grid.push_back({0,0,0,0,1,1,1,0,0,1,1,1,0,1,0});

    cout<<solve.shortestPath(grid, 27)<<endl;
}
