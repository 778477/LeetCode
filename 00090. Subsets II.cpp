/*
    [Subsets II](https://leetcode.com/problems/subsets-ii/)


    暴力枚举
*/


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        hashMap.clear();
        
        len = (unsigned)nums.size();
        
        for(unsigned i = 0; i <= len; i++){
            dfs({},0,0,i,ans,nums);
        }
        
        
        return ans;
    }
    
    void dfs(vector<int> tmp,unsigned star,unsigned step,unsigned total, vector<vector<int>> &ans,const vector<int> nums){
        if(step == total && !hashMap.count(tmp)){
            hashMap.insert(tmp);
            ans.push_back(tmp);
            return;
        }
        
        for(unsigned i = star; i < len; i++){
            tmp.push_back(nums[i]);
            dfs(tmp,i+1,step+1,total,ans,nums);
            tmp.pop_back();
        }
    }
    
private:
    set<vector<int>> hashMap;
    unsigned len;
};
