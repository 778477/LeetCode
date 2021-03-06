
//Accepted	116 ms	cpp
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans;

        vector<int> tmp;

        sort(candidates.begin(),candidates.end());

        dfs(ans,candidates,tmp,target);

        return ans;
    }

    void dfs(vector<vector<int> >& A,vector<int>& C,vector<int>& T,int target)
    {
        if(target == 0)
        {
            vector<int> tmp(T);
            A.push_back(tmp);
            return ;
        }
        for(int i=0;i<C.size();i++)
        {
            if(target >= C[i] &&(T.size() == 0 || C[i]>=T.back()))
            {
                T.push_back(C[i]);
                dfs(A,C,T,target-C[i]);
                T.pop_back();
            }
//            else return ;
        }
    }
};

