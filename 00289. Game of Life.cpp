
//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 289. Game of Life
 
 According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 
 Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 
 Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 Any live cell with two or three live neighbors lives on to the next generation.
 Any live cell with more than three live neighbors dies, as if by over-population..
 Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 Write a function to compute the next state (after one update) of the board given its current state.
 
 Follow up:
 Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
 In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 
 */

/**
 
 22 / 22 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool livetoNextState(int x,int y,const vector<vector<int>> board){
        int cnt = 0;
        for(int i = 0;i<8;++i){
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if(board[xx][yy]) ++cnt;
        }
        
        if(cnt == 2 || cnt == 3) return true;
        return false;
    }
    
    bool reproduction(int x,int y,const vector<vector<int>> board){
        int cnt = 0;
        for(int i = 0;i<8;++i){
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if(board[xx][yy]) ++cnt;
        }
        
        return cnt == 3;
    }
    void gameOfLife(vector<vector<int>>& board) {
        n = m = 0;
        vector<vector<int>> original = board;
        n = (int)original.size();
        if(n >= 1) m = (int)original[0].size();
        
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(original[i][j]){
                    board[i][j] = livetoNextState(i, j, original) ? 1 : 0;
                } else {
                    board[i][j] = reproduction(i, j, original) ? 1 : 0;
                }
            }
        }
        
    }
private:
    int n,m;
    const int dir[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
};


int main(int argc, const char * argv[]) {
    
    vector<vector<int>> board = {{1}};
    
    Solution solve;
    
    solve.gameOfLife(board);
    
    return 0;
}
