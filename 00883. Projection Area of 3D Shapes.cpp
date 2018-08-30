//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

/**
 
 883. Projection Area of 3D Shapes
 DescriptionHintsSubmissionsDiscussSolution
 On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.
 
 Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
 
 Now we view the projection of these cubes onto the xy, yz, and zx planes.
 
 A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane.
 
 Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
 
 Return the total area of all three projections.
 
 
 
 Example 1:
 
 Input: [[2]]
 Output: 5
 Example 2:
 
 Input: [[1,2],[3,4]]
 Output: 17
 Explanation:
 Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
 
 Example 3:
 
 Input: [[1,0],[0,2]]
 Output: 8
 Example 4:
 
 Input: [[1,1,1],[1,0,1],[1,1,1]]
 Output: 14
 Example 5:
 
 Input: [[2,2,2],[2,1,2],[2,2,2]]
 Output: 21
 
 
 Note:
 
 1 <= grid.length = grid[0].length <= 50
 0 <= grid[i][j] <= 50
 
 
 */


/**
 
 90 / 90 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
 */

static auto _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        
        
        for(auto i=0;i<grid.size(); ++i){
            for(auto j=0;j<grid[i].size(); ++j){
                if(grid[i][j] != 0){
                    ++ans;
                }
            }
        }
        
        
        for(auto i=0;i<grid.size(); ++i){
            ans += *max_element(grid[i].begin(), grid[i].end());
        }
        
        for(auto i=0;i<grid.size(); ++i){
            int tmp = 0;
            for(auto j=0;j<grid[i].size(); ++j){
                tmp = max(tmp, grid[j][i]);
            }
            ans += tmp;
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    
    
    return 0;
}

