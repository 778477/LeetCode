#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
1074. Number of Submatrices That Sum to Target

Given a matrix, and a target, return the number of non-empty submatrices that
sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <=
x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they
have some coordinate that is different: for example, if x1 != x1'.



Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2
submatrix.


Note:

1 <= matrix.length <= 300
1 <= matrix[0].length <= 300
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
 */

// 38 / 38 test cases passed.
// Status: Accepted
// Runtime: 7000 ms
// Memory Usage: 453 MB
class Solution {
  public:
	int numSubmatrixSumTarget(vector<vector<int>> &A, int target) {
		int ans = 0;
		int n = A.size(), m = A[0].size();
		int dp[n][m];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < m; i++) {
			dp[0][i] = A[0][i];
			for (int j = 1; j < n; j++) {
				dp[j][i] = dp[j - 1][i] + A[j][i];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				unordered_map<int, int> counter;
				int tmp = 0;
				counter[tmp] = 1;
				for (int k = 0; k < m; k++) {
					tmp += dp[j][k] - (i > 0 ? dp[i - 1][k] : 0);
					ans += counter[tmp - target];
					++counter[tmp];
				}
			}
		}
		return ans;
	}
};
int main() {
	Solution solve;
	vector<vector<int>> matrix = {{1, -1}, {-1, 1}};
	assert(solve.numSubmatrixSumTarget(matrix, 0) == 5);
	return 0;
}