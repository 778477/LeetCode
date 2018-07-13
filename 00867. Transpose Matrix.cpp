
//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>

#include <vector>
using namespace std;

/**
 
 867. Transpose Matrix
 
 Given a matrix A, return the transpose of A.
 
 The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
 
 
 
 Example 1:
 
 Input: [[1,2,3],[4,5,6],[7,8,9]]
 Output: [[1,4,7],[2,5,8],[3,6,9]]
 Example 2:
 
 Input: [[1,2,3],[4,5,6]]
 Output: [[1,4],[2,5],[3,6]]
 
 
 Note:
 
 1 <= A.length <= 1000
 1 <= A[0].length <= 1000
 
 
 */


/**
 
 
 36 / 36 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 
 */
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> B;
        
        
        for(size_t i = 0;i<A[0].size();++i){
            vector<int> tmp;
            for(size_t j = 0;j<A.size(); ++j){
                tmp.push_back(A[j][i]);
            }
            B.push_back(tmp);
        }
        
        return B;
    }
};

int main(int argc, const char * argv[]) {
    
    
    vector<vector<int>> A;
    A.push_back({1,2,3});
    A.push_back({4,5,6});
    //    A.push_back({7,8,9});
    
    Solution solve;
    vector<vector<int>> B = solve.transpose(A);
    
    for(vector<int> v : B){
        for(int num : v){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
