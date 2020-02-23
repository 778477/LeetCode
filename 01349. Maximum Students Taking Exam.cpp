// 55 / 55 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// Memory Usage: 8.7 MB

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size();
        int m = seats[0].size();
        vector<vector<int>> dp(n, vector<int>(1<<m, 0));
        auto isValidState = [&](int row, int state){
            bitset<8> bt(state);
            for(int i = 0; i<m; i++) {
                if(!bt[i]) continue;
                if(seats[row][i] != '.') return false;
                if(i-1>-1&&bt[i-1]) return false;
            }
            return true;
        };
        
        for(int i = 0; i<1<<m; i++) {
            bitset<8> bt(i);
            dp[0][i] = isValidState(0, i) ? (int)bt.count() : 0;
        }
        int ans = 0;
        for(int i = 1;i<n; i++) {
            for(int j = 0; j<1<<m; j++) {
                if(!isValidState(i, j)) continue;
                bitset<8> jbt(j);
                dp[i][j] = (int)jbt.count();
                
                for(int k = 0; k<1<<m; k++) {
                    bitset<8> kbt(k);
                    bool can = true;
                    for(int a = 0; a<m; a++) {
                        if(!jbt[a]) continue;
                        if((a-1>-1&&kbt[a-1]) || (a+1<m&&kbt[a+1])) {
                            can = false;
                            break;
                        }
                    }
                    
                    if(can) {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] + (int)jbt.count());
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};