//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;



/**
 https://leetcode.com/problems/minimum-falling-path-sum/
 
 Given a square array of integers A, we want the minimum sum of a falling path through A.
 
 A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.
 
 
 
 Example 1:
 
 Input: [[1,2,3],[4,5,6],[7,8,9]]
 Output: 12
 Explanation:
 The possible falling paths are:
 [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
 [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
 [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
 The falling path with the smallest sum is [1,4,7], so the answer is 12.
 
 
 
 Note:
 
 1 <= A.length == A[0].length <= 100
 -100 <= A[i][j] <= 100
 
 */

/**
 
 
 46 / 46 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */



// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
    public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = (int)A.size();
        for(int i=1; i<n;++i){
            for(int j=0; j<n; ++j){
                int tmp = A[i-1][j];
                if(j - 1 > -1) tmp = min(tmp, A[i-1][j-1]);
                if(j + 1 <  n) tmp = min(tmp, A[i-1][j+1]);
                A[i][j] = A[i][j] + tmp;
            }
        }
        return *min_element(A[n-1].begin(), A[n-1].end());
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<solve.minFallingPathSum(nums)<<endl;
    return 0;
}

