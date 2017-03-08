//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>


#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 529. Minesweeper
 
 Let's play the minesweeper game (Wikipedia, online game)!
 
 You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
 
 Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:
 
 If a mine ('M') is revealed, then the game is over - change it to 'X'.
 If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
 If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
 Return the board when no more squares will be revealed.
 
 
 Example 1:
 Input:
 
 [['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]
 
 Click : [3,0]
 
 Output:
 
 [['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]
 
 
 Example 2:
 Input:
 
 [['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]
 
 Click : [1,2]
 
 Output:
 
 [['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]
 
 
 Note:
 The range of the input matrix's height and width is [1,50].
 The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
 The input board won't be a stage when game is over (some mines have been revealed).
 For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
 
 
 */


/**
 
 Depth-first Search / Breadth-first Search
 
 54 / 54 test cases passed.
 Status: Accepted
 Runtime: 176 ms
 
 */

typedef pair<int, int> point;
class Solution {
private:
    const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        point clickP = make_pair(click[0], click[1]);
        
        int cnt = checkAround(clickP,board);
        if(board[clickP.first][clickP.second] == 'M'){
            board[clickP.first][clickP.second] = 'X';
        } else if(cnt > 0){
            board[clickP.first][clickP.second] = ('0' + cnt);
        } else{
            reveal(clickP,board);
        }
        
        
        return board;
    }
    
    void reveal(const point p,vector<vector<char>>& board){
        board[p.first][p.second] = 'B';
        
        for(int i=0;i<8;i++){
            point newP = make_pair(p.first + dir[i][0], p.second + dir[i][1]);
            
            if(isValidPoint(newP, board) && board[newP.first][newP.second] == 'E'){
                int cnt = checkAround(newP, board);
                if(cnt > 0){
                    board[newP.first][newP.second] = ('0' + cnt);
                } else{
                    reveal(make_pair(newP.first, newP.second), board);
                }
            }
            
        }
    }
    
    bool isValidPoint(const point p,const vector<vector<char>> board){
        return (p.first > -1 && p.first < board.size() && p.second > -1 && p.second < board[p.first].size());
    }
    
    int checkAround(const point p,const vector<vector<char>> board){
        int count = 0;
        
        for(int i = 0;i<8;i++){
            int xx = p.first + dir[i][0];
            int yy = p.second + dir[i][1];
            
            if(isValidPoint(make_pair(xx, yy), board)){
                if(board[xx][yy] == 'M') count++;
            }
        }
        
        return count;
    }
};

int main(){
    
    
    return 0;
}
