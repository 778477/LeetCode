
//Accepted	36 ms	cpp
class Solution {
private:
    int _maze[101][101];
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        memset(_maze, 0, sizeof(_maze));
        
        int n = (int)obstacleGrid.size();
        int m = (int)obstacleGrid[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(obstacleGrid[i][0]) break;
            _maze[i][0] = 1;
        }
        
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[0][i]) break;
            _maze[0][i] = 1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(obstacleGrid[i][j]) continue;
                _maze[i][j] = _maze[i-1][j] + _maze[i][j-1];
            }
        }
        
        return _maze[n-1][m-1];
    }
    
};
