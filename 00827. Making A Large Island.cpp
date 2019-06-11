
/**
 
 63 / 63 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 Memory Usage: 11.6 MB
 
 */

class Solution {
public:
    const int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int n,m;
    void dfs(int x,int y, vector<vector<int>>& g,int c, int &cnt){
        g[x][y] = c;
        ++cnt;
        
        for(int k=0;k<4;k++){
            int xx = x + dir[k][0];
            int yy = y + dir[k][1];
            if(xx>-1 && xx < n && yy > -1 && yy < m && g[xx][yy] == 1){
                dfs(xx,yy,g,c,cnt);
            }
        }
    }
    int largestIsland(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        
        int c = 2;
        int ans = 0;
        unordered_map<int,int> area;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(g[i][j] == 1){
                    int tmp = 0;
                    dfs(i,j,g,c,tmp);
                    area[c] = tmp;
                    ans = max(ans, tmp);
                    ++c;
                }
            }
        }
        
        
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(g[i][j] == 0){
                    set<int> cs;
                    int tmp = 1;
                    for(int k=0;k<4;k++){
                        int xx = i + dir[k][0];
                        int yy = j + dir[k][1];
                        if(xx>-1 && xx < n && yy > -1 && yy < m && g[xx][yy] > 1 && cs.find(g[xx][yy]) == cs.end()){
                            cs.insert(g[xx][yy]);
                            tmp += area[g[xx][yy]];
                        }
                    }
                    ans = max(tmp, ans);
                }
            }
        }
        return ans;
    }
};
