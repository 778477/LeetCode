/*
[Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)


暴力枚举
*/


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        
        dfs(1,4,1,s,{0},ans);
        
        return ans;
    }
    
    void dfs(unsigned step, unsigned total, unsigned star, const string& str,vector<unsigned> idxs, vector<string>& ans){
        if( (str.size() - star)*1.0 / (total - step + 1) > 3.0) return;
        
        if(step == total && vaildIPSection(str, idxs[step - 1], (unsigned)str.size())){
            string tmp = str;
            for(int i=1;i<total;i++){
                tmp.insert(idxs[i]+i-1, ".");
            }
            ans.push_back(tmp);
        }
        
        for(unsigned i = star; i < str.size(); i++){
            if(vaildIPSection(str, idxs[step - 1], i)){
                idxs.push_back(i);
                dfs(step+1, total, i+1, str, idxs, ans);
                idxs.pop_back();
            }
        }
    }
    
    bool vaildIPSection(const string& str,unsigned star,unsigned end){
        unsigned num = 0;
        
        for(unsigned i = star; i < end; i++){
            num = num*10 + (str[i] - '0');
        }
        
        if(end - star > 1){
            unsigned limit = pow(10,(end-star-1)) - 1;
            if(num <= limit) return false;
        }
        
        return num <= 255;
    }
};

