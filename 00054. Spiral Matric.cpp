
//	Accepted	4 ms	cpp
class Solution {
private:
    unsigned _n,_m;
    char _star;
    const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        _n    = (int)matrix.size();
        if(_n < 1) return ans;
        _m    = (int)matrix[0].size();
        _star = 0;
        
        
        int count = _n*_m;
        int x,y,xx,yy;
        x = y = 0;
        while(count--)
        {
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -778477;
            xx = x + dir[_star][0];
            yy = y + dir[_star][1];
            if(judge(xx, yy) && matrix[xx][yy] != -778477)
                x = xx , y = yy;
            else
            {
                _star = (_star+1)%4;
                x = x + dir[_star][0];
                y = y + dir[_star][1];
            }
        }
        
        return ans;
    }
    bool judge(const int x,const int y)
    {
        return (x>-1&&x<_n&&y>-1&&y<_m);
    }
};
