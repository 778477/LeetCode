//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

/**
 
 419. Battleships in a Board
 
 Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
 
 You receive a valid board, made of only battleships or empty slots.
 Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
 At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
 
 Z X..X
 ...X
 ...X
 In the above board there are 2 battleships.
 
 Invalid Example:
 ...X
 XXXX
 ...X
 This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
 Follow up:
 Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
 
 */


/**
 
 28 / 28 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        
        for(int i=0;i<board.size();i++){
            for (int j=0; j<board[i].size(); j++) {
                if(board[i][j] == 'X'){
                    count++;
                    dfs(i,j,board);
                }
            }
        }
        
        return count;
    }
    
    void dfs(int x,int y, vector<vector<char>>& board){
        board[x][y] ='.';
        
        for(int i=0;i<4;i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            
            if(xx>-1 && xx< board.size() && yy>-1 && yy<board[xx].size()){
                if(board[xx][yy] == 'X'){
                    dfs(xx, yy, board);
                }
            }
        }
    }
private:
    const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
};


int main(){
    
    
    return 0;
}
