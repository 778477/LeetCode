#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

/**
 * 
 * 
1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbours of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if they share one edge.

Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

Binary matrix is a matrix with all cells equal to 0 or 1 only.

Zero matrix is a matrix with all cells equal to 0.

 

Example 1:


Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
Example 2:

Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We don't need to change it.
Example 3:

Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
Output: 6
Example 4:

Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix can't be a zero matrix
 

Constraints:

m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] is 0 or 1.
 **/

// 24 / 24 test cases passed.
// Status: Accepted
// Runtime: 32 ms
// Memory Usage: 16.7 MB
class Solution {
public:
    unordered_map<int, int> vis;
    int n, m;
    int matToStateCode(vector<vector<int>>& mat){
        int code = 0;
        int ibit = 1;
        for(int i = 0; i<this->n; i++){
            int tmp = 0;
            for(int j = 0; j<this->m; j++){
                tmp = tmp + (mat[i][j]<<(this->m-j-1));
            }
            code = tmp*ibit + code;
            ibit <<= this->m;
        }
        return code;
    }

    vector<vector<int>> statCodeToMat(int statCode){
        vector<vector<int>> mat;
        for(int i = 0; i<this->n; i++){
            vector<int> tmp;
            int mask = 1<<(this->m - 1);
            for(int j = 0; j<this->m; j++){
                tmp.push_back(statCode & mask ? 1 : 0);
                mask >>= 1;
            }
            mat.push_back(tmp);
            statCode >>= this->m;
        }
        return mat;
    }

    int filp(int statCode, int x, int y){
        vector<vector<int>> mat = statCodeToMat(statCode);
        mat[x][y] = !mat[x][y];
        if(x + 1 < this->n) mat[x+1][y] = !mat[x+1][y];
        if(y + 1 < this->m) mat[x][y+1] = !mat[x][y+1];
        if(x - 1 > -1) mat[x-1][y] = !mat[x-1][y];
        if(y - 1 > -1) mat[x][y-1] = !mat[x][y-1];
        return matToStateCode(mat);
    }

    void output(int original, int next, int x, int y){
        cout<<"filp :"<<x<<","<<y<<":"<<endl;
        vector<vector<int>> oriMat = statCodeToMat(original);
        vector<vector<int>> nextMat = statCodeToMat(next);
        for(int i = 0; i<this->n; i++){
            for(int j = 0; j<this->m; j++){
                cout<<oriMat[i][j]<<",";
            }
            for(int j=0; j<5; j++){
                cout<<(i==0?"-":" ");
            }
            cout<<(i==0?">":" ");
            for(int j = 0; j<this->m;j++){
                cout<<nextMat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int bfs(vector<vector<int>>& mat){
        vis.clear();
        using state = pair<int, int>;
        queue<state> q;
        int code = matToStateCode(mat);
        vis[code] = 1;
        q.push({code, 0});
        while(!q.empty()){
            state now = q.front();
            q.pop();
            if(now.first == 0) return now.second;

            for(int i = 0; i<this->n; i++){
                for(int j = 0; j<this->m; j++){
                    int next = filp(now.first, i, j);
                    if(vis.find(next) == vis.end()){
                        vis[next] = 1;
                        // output(now.first, next, i, j);
                        q.push({next, now.second + 1});
                    }
                }
            }
        }

        return -1;
    }

    int minFlips(vector<vector<int>>& mat) {
        this->n = mat.size();
        this->m = mat[0].size();
        return bfs(mat);
    }
};

int main(){
    Solution solve;
    vector<vector<int>> matrix;
    matrix.push_back({1,1,1});
    matrix.push_back({1,0,1});
    matrix.push_back({0,0,0});
    cout<<solve.minFlips(matrix)<<endl;
}