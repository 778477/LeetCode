
//Accepted	32 ms	cpp
class Solution {
public:
    Solution(){
        memset(row,false,sizeof(row));
        memset(block,false,sizeof(block));
        memset(col,false,sizeof(col));
        memset(validArray,-1,sizeof(validArray));
        len = 0;
        flag = false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        for(unsigned i=0;i<board.size();i++)
        {
            for(unsigned j=0;j<board[i].size();j++)
            {
                if(board[i][j] == '.') validArray[len++] = i*N+j;
                else
                {
                    int num = board[i][j] - '0';
//                    cout<<num<<" "<<col[j][num]<<endl;
                    if(row[i][num]) return ;
                    row[i][num] = true;
                    if(col[j][num]) return ;
                    col[j][num] = true;
                    if(block[(i/3)*3 + j/3][num]) return ;
                    block[(i/3)*3 + j/3][num] = true;

                }
            }
        }
//        printf("break\n");
//        flag = false;
        dfs(0,board);
    }
    void dfs(int step,vector<vector<char> > &board)
    {
//        printf("now is the step %d len = %d\n",step,len);
        if(flag) return ;
        if(step == len)
        {
            flag = true;
            return ;
        }
        int r = validArray[step]/N;
        int c = validArray[step]%N;
        for(int i=1;i<10;i++)
        {
            if(!row[r][i] && !col[c][i] && !block[(r/3)*3 + c/3][i])
            {
                row[r][i] = true;
                col[c][i] = true;
                block[(r/3)*3 + c/3][i] = true;
                board[r][c] = '0'+i;
                dfs(step+1,board);
                if(flag) return ;
                row[r][i] = false;
                col[c][i] = false;
                block[(r/3)*3 + c/3][i] = false;
                board[r][c] = '.';
            }
        }
    }
private:
    static const int N = 10;
    bool row[N][N],block[N][N],col[N][N];
    int validArray[N*N],len;
    bool flag;
};

