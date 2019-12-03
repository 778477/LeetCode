#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

/**
 * 
 * 1277. Count Square Submatrices with All Ones
 * 
 * Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
 * 
 **/

// 32 / 32 test cases passed.
// Status: Accepted
// Runtime: 68 ms
// Memory Usage: 18.7 MB

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            dp[i][1] = dp[i-1][1] + matrix[i-1][0];
        }
        for(int i=1; i<=m; i++){
            dp[1][i] = dp[1][i-1] + matrix[0][i-1];
        }

        for(int i = 2; i<=n; i++){
            for(int j = 2; j<=m; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1];
            }
        }

        int slide = min(n, m);
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                for(int k = 1; k<=slide; ++k){
                    if(i + k > n || j + k > m) break;
                    int ii = i + k;
                    int jj = j + k;
                    int val = dp[ii][jj] - dp[i][jj] - dp[ii][j] + dp[i][j];
                    if(val == k*k) {
                        ++ans;
                    } else {
                         break;
                    }
                }
            }
        }

        return ans;
    }
};

/**
 * [
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
 */ 
int main(){
    Solution *solve = new Solution();
    vector<vector<int>> matrix;
    matrix.push_back({0,1,1,1});
    matrix.push_back({1,1,1,1});
    matrix.push_back({0,1,1,1});
    cout<<solve->countSquares(matrix)<<endl;
    
    return 0;
}
