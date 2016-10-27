
//Accepted	4 ms	cpp
class Solution {
private:
    int _maze[101][101];
public:
    int uniquePaths(int m, int n) {
        memset(_maze, 0, sizeof(_maze));
        
        for(int i=0;i<m;i++)
            _maze[i][0] = 1;
        for(int i=0;i<n;i++)
            _maze[0][i] = 1;
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
                _maze[i][j] = _maze[i-1][j] + _maze[i][j-1];
        }
        
        
        return _maze[m-1][n-1];
    }
    
};
