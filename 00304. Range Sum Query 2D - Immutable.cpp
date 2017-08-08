
//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;



/**
 
 304. Range Sum Query 2D - Immutable
 
 Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 
 Range Sum Query 2D
 The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
 
 Example:
 Given matrix = [
 [3, 0, 1, 4, 2],
 [5, 6, 3, 2, 1],
 [1, 2, 0, 1, 5],
 [4, 1, 0, 1, 7],
 [1, 0, 3, 0, 5]
 ]
 
 sumRegion(2, 1, 4, 3) -> 8
 sumRegion(1, 1, 2, 2) -> 11
 sumRegion(1, 2, 2, 4) -> 12
 Note:
 You may assume that the matrix does not change.
 There are many calls to sumRegion function.
 You may assume that row1 ≤ row2 and col1 ≤ col2.
 
 */


/**
 Range Sum Query - Immutable 二维版本，因为是不可改变数据(没有更新操作)直接用离线计算存储结算结果即可
 
 12 / 12 test cases passed.
 Status: Accepted
 Runtime: 36 ms
 */

class NumMatrix {
private:
    vector<vector<int>> rowSum;
    vector<vector<int>> _matrix;
public:
    NumMatrix(vector<vector<int>> matrix) {
        unsigned long n = matrix.size();
        unsigned long m = n > 0 ? matrix[0].size() : 0;
        rowSum = vector<vector<int>> (m,vector<int>(static_cast<int>(n),0));
        _matrix = matrix;
        
        for(size_t i = 0; i < m; ++i){
            for(size_t j = 0; j < n; ++j){
                rowSum[i][j] = j > 0 ? rowSum[i][j-1] + matrix[j][i] : matrix[j][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = col1; i<=col2;++i){
            ans += (rowSum[i][row2] - rowSum[i][row1] + _matrix[row1][i]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main(){
    
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{3, 0, 1, 4, 2});
    matrix.push_back(vector<int>{5, 6, 3, 2, 1});
    matrix.push_back(vector<int>{1, 2, 0, 1, 5});
    matrix.push_back(vector<int>{4, 1, 0, 1, 7});
    matrix.push_back(vector<int>{1, 0, 3, 0, 5});
    
    NumMatrix numMatrix(matrix);
    
    //    sumRegion(2, 1, 4, 3) -> 8
    //    sumRegion(1, 1, 2, 2) -> 11
    //    sumRegion(1, 2, 2, 4) -> 12
    
    cout<<numMatrix.sumRegion(0, 1, 0, 3)<<endl;
    cout<<numMatrix.sumRegion(1, 1, 2, 2)<<endl;
    cout<<numMatrix.sumRegion(1, 2, 2, 4)<<endl;
    
    return 0;
}


