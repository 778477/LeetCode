//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 
 864. Shortest Path to Get All Keys
 
 We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.
 
 We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.
 
 For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
 
 Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.
 
 
 
 Example 1:
 
 Input: ["@.a.#","###.#","b.A.B"]
 Output: 8
 Example 2:
 
 Input: ["@..aA","..B#.","....b"]
 Output: 6
 
 
 Note:
 
 1 <= grid.length <= 30
 1 <= grid[0].length <= 30
 grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
 The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.
 
 */


/**
 
 35 / 35 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
 使用三维数组表示 当前状态 (x,y,keys) => 位置信息+钥匙串🔑
 钥匙去重(重复获得相同的钥匙不计数即可)
 
 */

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

typedef pair<int, int> point;
class State{
public:
    int step,keys;
    point p;
    State(int _s,int _keys,point _p){
        step = _s;
        keys = _keys;
        p = _p;
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        
        queue<State> road;
        unsigned totalKeyCount = 0;
        
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        for(size_t i = 0; i<n; ++i){
            for(size_t j = 0;j<m; ++j){
                if(grid[i][j] == '@'){
                    road.push(State(0, 0, make_pair(i, j)));
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    ++totalKeyCount;
                }
            }
        }
        
        const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<vector<int>>> vis{31,vector<vector<int>>{31,vector<int>(64,31*31)}};
        vis[road.front().p.first][road.front().p.second][road.front().keys] = 0;
        while(!road.empty()){
            State now = road.front();
            road.pop();
            
            if(now.keys == (1<<totalKeyCount) - 1){
                return now.step;
            }
            
            for(int i = 0; i<4; ++i){
                int xx = now.p.first + dir[i][0];
                int yy = now.p.second + dir[i][1];
                
                if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
                if(grid[xx][yy] == '#') continue;
                
                
                if(grid[xx][yy] >= 'A' && grid[xx][yy] <= 'F'){
                    int lock = 1 << (grid[xx][yy] - 'A');
                    if(!(now.keys&lock)){
                        continue;
                    }
                }
                
                State next(now.step +1,now.keys,make_pair(xx, yy));
                if(grid[xx][yy]>='a' && grid[xx][yy]<='f'){
                    int tmpKey = 1 << (grid[xx][yy] - 'a');
                    next.keys = next.keys | tmpKey;
                }
                
                if(next.step < vis[next.p.first][next.p.second][next.keys]){
                    vis[next.p.first][next.p.second][next.keys] = next.step;
                    road.push(next);
                }
            }
        }
        return -1;
    }
};

/**
 ["@...a",".###A","b.BCc"] => 10
 */

int main(int argc, const char * argv[]) {
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    
    vector<string> maze;
    maze.push_back("@...a");
    maze.push_back(".###A");
    maze.push_back("b.BCc");
    
    Solution solve;
    cout<<solve.shortestPathAllKeys(maze)<<endl;
    
    return 0;
}

