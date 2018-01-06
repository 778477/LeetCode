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
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 240. Search a 2D Matrix II
 
 
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted in ascending from left to right.
 Integers in each column are sorted in ascending from top to bottom.
 For example,
 
 Consider the following matrix:
 
 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]
 Given target = 5, return true.
 
 Given target = 20, return false.
 
 
 
 */


/**
 
 
 129 / 129 test cases passed.
 Status: Accepted
 Runtime: 43 ms
 
 */



bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    
    int x = matrixRowSize - 1, y = 0;
    
    while( x > -1 && x < matrixRowSize && y > -1 && y < matrixColSize){
        
        if(target == matrix[x][y]){
            return true;
        }
        
        if(target > matrix[x][y]){
            ++y;
        } else {
            --x;
        }
        
    }
    
    return false;
}


int main(){
    
    
    
    return 0;
}
