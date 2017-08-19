/**
 Status: Accepted
 Runtime: 16 ms
 Submitted: 1 year, 4 months ago
*/

const int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
bool vis[1024][1024];
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        int n = (int)grid.size();
        if(!n) return count;
        int m = (int)grid[0].size();
        memset(vis, false, sizeof(bool) * 1024 * 1024);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i,j,n,m,grid);
                    count++;
                }
            }
        }
        
        return count;
    }
    
    void bfs(int x,int y,int n,int m,const vector<vector<char>>& grid){
        queue<pair<int, int>> Q;
        Q.push(make_pair(x, y));
        
        while(!Q.empty()){
            pair<int, int> star = Q.front();
            Q.pop();
            vis[star.first][star.second] = true;
            for(int i=0;i<4;i++){
                int xx = star.first + dir[i][0];
                int yy = star.second + dir[i][1];
                
                if(xx>-1&&xx<n&&yy>-1&&yy<m&&!vis[xx][yy]&&grid[xx][yy] == '1'){
                    vis[xx][yy] = true;
                    Q.push(make_pair(xx, yy));
                }
            }
        }
    }
};
