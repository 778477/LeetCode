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
 
 
 766. Toeplitz Matrix
 
 A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
 
 Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 
 
 Example 1:
 
 Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 Output: True
 Explanation:
 1234
 5123
 9512
 
 In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
 Example 2:
 
 Input: matrix = [[1,2],[2,2]]
 Output: False
 Explanation:
 The diagonal "[1, 2]" has different elements.
 Note:
 
 matrix will be a 2D array of integers.
 matrix will have a number of rows and columns in range [1, 20].
 matrix[i][j] will be integers in range [0, 99].
 
 
 
 
 
 */


/**
 
 443 / 443 test cases passed.
 Status: Accepted
 Runtime: 24 ms
 
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = (int)matrix.size();
        int col = row > 0 ? (int)matrix[0].size() : 0;
        if(col == 0) return true;
        
        int x,y;
        for(int i=0;i<col;++i){
            x = 0, y = i;
            while(x+1 < row && y + 1 < col){
                if(matrix[x+1][y+1] != matrix[0][col]) return false;
                
                ++x,++y;
            }
        }
        
        for(int i=0;i<row;++i){
            x = i,y = 0;
            
            while(x+1<row && y+1<col){
                if(matrix[x+1][y+1] != matrix[row][0]) return false;
                
                ++x,++y;
            }
        }
        
        
        return true;
    }
};

int main(){
    
    
    
    
    return 0;
}
