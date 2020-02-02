
//Accepted    740 ms    8.9 MB    cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        if (d > jobs.size()) return -1;
        if (d == jobs.size()) return accumulate(jobs.begin(), jobs.end(), 0);
        int n = jobs.size();
        constexpr int INF = 0x3fff3fff;
        vector<vector<int>> dp = vector<vector<int>>(d, vector<int>(n, INF));
        dp[0][0] = jobs[0];
        for(int i = 1; i<jobs.size(); i++) dp[0][i] = max(jobs[i], dp[0][i-1]);
        
        for(int i = 1; i<d; i++) {
            for(int j = i; j<n; j++) {
                for(int k = i-1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + *max_element(jobs.begin() + k + 1, jobs.begin() + j + 1));
                }
            }
        }
        
        return dp[d-1][n-1];
    }
};


//`Accepted    32 ms    14.6 MB    cpp`
//
//新增cost数组，预处理好max{i...j}数据让
//`*max_element(jobs.begin() + k + 1, jobs.begin() + j + 1))`
//复杂度变成`O(1)`

class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        if (d > jobs.size()) return -1;
        if (d == jobs.size()) return accumulate(jobs.begin(), jobs.end(), 0);

        int n = jobs.size();
        constexpr int INF = 0x3fff3fff;
        vector<vector<int>> dp = vector<vector<int>>(d, vector<int>(n, INF));
        vector<vector<int>> cost = vector<vector<int>>(n, vector<int>(n, 0));
        
        for(int i = 0; i<n; i++) {
            cost[i][i] = jobs[i];
            for(int j = i+1; j<n; j++) {
                cost[i][j] = max(cost[i][j-1], jobs[j]);
            }
            dp[0][i] = cost[0][i];
        }
        
        for(int i = 1; i<d; i++) {
            for(int j = i; j<n; j++) {
                for(int k = i-1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + cost[k+1][j]);
                }
            }
        }
        
        return dp[d-1][n-1];
    }
};

