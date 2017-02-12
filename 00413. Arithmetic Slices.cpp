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
 
 413. Arithmetic Slices
 
 A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 
 For example, these are arithmetic sequence:
 
 1, 3, 5, 7, 9
 7, 7, 7, 7
 3, -1, -5, -9
 The following sequence is not arithmetic.
 
 1, 1, 2, 5, 7
 
 A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 
 A slice (P, Q) of array A is called arithmetic if the sequence:
 A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 
 The function should return the number of arithmetic slices in the array A.
 
 
 Example:
 
 A = [1, 2, 3, 4]
 
 return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 
 */


/**
 
 15 / 15 test cases passed.
 Status: Accepted
 Runtime: 63 ms
 
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        
        for(int i=3;i<=A.size();i++){
            for(int j=0;j<= A.size() - i;j++){
                // slice [j,j+i];
                int tmp = A[j+1] - A[j];
                bool flag = false;
                for(int k=j+1;k+1 < j+i;k++){
                    if(A[k+1] - A[k] != tmp){
                        flag = true;
                        break;
                    }
                }
                
                if(!flag){
                    ++ans;
                    for(int k=j;k<j+i;k++){
                        cout<<A[k]<<",";
                    }
                    cout<<endl;
                }
            }
        }
        
        return ans;
    }
};

/**
 
 1, 3, 5, 7, 9
 7, 7, 7, 7
 3, -1, -5, -9
 
 
 */

int main(){
    
    Solution solve;
    
    vector<int> nums{1,2,3,4,0,7,8,9};
    
    
    cout<<solve.numberOfArithmeticSlices(nums)<<endl;
    
    return 0;
}
