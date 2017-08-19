/**
 Status: Accepted
 Runtime: 2 ms
 Submitted: 1 year, 2 months ago
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmpVct;
        dfs(1,0,0,tmpVct,ans,k,n);
        
        return ans;
    }
private:
    void dfs(int starVal,int step,int total,vector<int>& tmpVct,vector<vector<int>>& ans,const int k,const int n){
        if(step < k && starVal > n - total) return;
        if(step > k) return;
        if(step == k && total < n) return;
        if(step == k && total == n){
            ans.push_back(tmpVct);
            return;
        }
        
        
        for(int i=starVal; i<10; ++i){
            tmpVct.push_back(i);
            dfs(i+1, step+1, total+i, tmpVct, ans, k, n);
            tmpVct.pop_back();
        }
    }
};
