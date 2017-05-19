//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 566. Reshape the Matrix
 
 In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.
 
 You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.
 
 The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.
 
 If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
 
 Example 1:
 Input:
 nums =
 [[1,2],
 [3,4]]
 r = 1, c = 4
 Output:
 [[1,2,3,4]]
 Explanation:
 The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
 Example 2:
 Input:
 nums =
 [[1,2],
 [3,4]]
 r = 2, c = 4
 Output:
 [[1,2],
 [3,4]]
 Explanation:
 There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
 Note:
 The height and width of the given matrix is in range [1, 100].
 The given r and c are all positive.
 
 
 */

/*
 
 56 / 56 test cases passed.
 Status: Accepted
 Runtime: 43 ms
 
 */


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        unsigned long n = 0,m = 0;
        if(nums.size() > 0){
            n = nums.size();
            m = nums[0].size();
        }
        if(n*m != r*c) return nums;
        
        vector<vector<int>> ans;
        for(int i=0;i<r;i++){
            vector<int> tmp;
            for(int j=0;j<c;j++){
                int v = i*c+j;
                tmp.push_back(nums[v/m][v%m]);
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};

int main(){
    
    Solution solve;
    
    vector<int> t1{1,2,3,4,5};
    vector<int> t2{6,7,8,9,10};
    
    vector<vector<int>> nums;
    nums.push_back(t1);
    nums.push_back(t2);
    
    vector<vector<int>> ans = solve.matrixReshape(nums, 10, 1);
    
    for(vector<int> r : ans){
        for(int n : r){
            cout<<n<<",";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
