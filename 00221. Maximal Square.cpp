/**
 Status: Accepted
 Runtime: 12 ms
 Submitted: 1 year, 7 months ago
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    
                    ans = max(dp[i][j], ans);
                }
            }
        }
        
        return ans*ans;
    }
    
};
