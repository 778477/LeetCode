
//	Accepted	44 ms	cpp
class Solution {
private:
    vector<vector<int> > _ans;
    vector<bool> _vis;
    vector<int> _S;
    int _n;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        _ans.clear();
        _ans.push_back(vector<int>());
        
        _vis = vector<bool>(S.size() + 1,false);
        _n = (int)S.size();
        _S = S;
        sort(_S.begin(), _S.end());
        
        vector<int> tmp;
        for(unsigned i=1;i<=S.size();i++)
        {
            tmp.clear();
            dfs(0,i,tmp);
        }
        return _ans;
    }
    void dfs(int step,int n,vector<int>& tmp)
    {
        if(step == n)
        {
            _ans.push_back(tmp);
            return;
        }
        
        for(int i=step;i<_n;i++)
        {
            if(!_vis[i])
            {
                if(step && tmp[step-1] > _S[i]) continue;
                tmp.push_back(_S[i]);
                _vis[i] = true;
                dfs(step+1, n,tmp);
                _vis[i] = false;
                tmp.pop_back();
            }
        }
    }
};

