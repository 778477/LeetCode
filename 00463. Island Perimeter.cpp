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
 
 463. Island Perimeter
 
 You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 
 Example:
 
 [[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
 
 Answer: 16
 Explanation: The perimeter is the 16 yellow stripes in the image below:
 https://leetcode.com/static/images/problemset/island.png
 
 */


/**
 
 5833 / 5833 test cases passed.
 Status: Accepted
 Runtime: 99 ms
 
 */

static const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int lookARound(int x,int y,int **grid,int rowSize,int colSize){
    int ans = 4;
    
    for(int i=0;i<4;i++){
        int xx = x+dir[i][0];
        int yy = y+dir[i][1];
        
        if(xx>-1&&xx<rowSize&&yy>-1&&yy<colSize){
            if(grid[xx][yy]){
                --ans;
            }
        }
    }
    
    return ans;
}

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int ans = 0;
    
    for(int i=0;i<gridRowSize;i++){
        for(int j=0;j<gridColSize;j++){
            if(grid[i][j]){
                ans += lookARound(i,j,grid,gridRowSize,gridColSize);
            }
        }
    }
    
    return ans;
}



int main(){
    
    
    return 0;
}
