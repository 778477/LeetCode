//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//


#include <iostream>
#include <set>
#include <map>
#include <list>
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
 
 959. Regions Cut By Slashes
 DescriptionHintsSubmissionsDiscussSolution
 In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.
 
 (Note that backslash characters are escaped, so a \ is represented as "\\".)
 
 Return the number of regions.
 
 
 
 Example 1:
 
 Input:
 [
 " /",
 "/ "
 ]
 Output: 2
 Explanation: The 2x2 grid is as follows:
 
 Example 2:
 
 Input:
 [
 " /",
 "  "
 ]
 Output: 1
 Explanation: The 2x2 grid is as follows:
 
 Example 3:
 
 Input:
 [
 "\\/",
 "/\\"
 ]
 Output: 4
 Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
 The 2x2 grid is as follows:
 
 Example 4:
 
 Input:
 [
 "/\\",
 "\\/"
 ]
 Output: 5
 Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
 The 2x2 grid is as follows:
 
 Example 5:
 
 Input:
 [
 "//",
 "/ "
 ]
 Output: 3
 Explanation: The 2x2 grid is as follows:
 
 
 
 Note:
 
 1 <= grid.length == grid[0].length <= 30
 grid[i][j] is either '/', '\', or ' '.
 
 */


/**
 
 并查集，难点在于构图
 
 https://i.loli.net/2018/12/20/5c1b3cfd6c7b9.jpg
 
 137 / 137 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
 
 */
class Solution {
public:
    int find(vector<int>& parent, int p){
        while(parent[p] != p){
            p = parent[p];
            parent[p] = parent[parent[p]];
        }
        return parent[p];
    }
    void merge(vector<int>& parent, int p, int q){
        int a = find(parent, p);
        int b = find(parent, q);
        if(a == b) return;
        parent[a] = b;
    }
    int regionsBySlashes(vector<string>& grid) {
        int ans = 0;
        vector<int> parent(grid.size()*grid.size()*4, 0);
        iota(parent.begin(), parent.end(), 0);
        
        
        for(auto i=0; i<grid.size(); ++i){
            for(auto j=0;j<grid[i].length(); ++j){
                
                if(j + 1 < grid[i].length()){
                    merge(parent, 4*(i*grid.size() + j) + 2, 4*(i*grid.size() + j + 1) + 0);
                }
                
                if(i + 1 < grid.size()){
                    merge(parent, 4*(i*grid.size() + j) + 3, 4*((i+1)*grid.size() + j) + 1);
                }
                
                if(grid[i][j] == ' '){
                    // merge  all grid
                    merge(parent, 4*(i*grid.size() + j) + 0, 4*(i*grid.size() + j) + 1);
                    merge(parent, 4*(i*grid.size() + j) + 1, 4*(i*grid.size() + j) + 2);
                    merge(parent, 4*(i*grid.size() + j) + 2, 4*(i*grid.size() + j) + 3);
                } else if(grid[i][j] == '/'){
                    merge(parent, 4*(i*grid.size() + j) + 0, 4*(i*grid.size() + j) + 1);
                    merge(parent, 4*(i*grid.size() + j) + 2, 4*(i*grid.size() + j) + 3);
                } else {
                    merge(parent, 4*(i*grid.size() + j) + 1, 4*(i*grid.size() + j) + 2);
                    merge(parent, 4*(i*grid.size() + j) + 0, 4*(i*grid.size() + j) + 3);
                }
            }
        }
        
        for(auto i=0;i<parent.size();++i){
            if(i == find(parent, i)) ++ans;
        }
        
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<string> grid = {"/\\",
        "\\/"};
    
    cout<<solve.regionsBySlashes(grid)<<endl;
    return 0;
}

