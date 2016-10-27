
//Accepted	19 ms	cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        
        dfs(root,sum,ans,{});
        
        return ans;
    }
    
    void dfs(TreeNode *root,const int sum,vector<vector<int>> &ans,vector<int> tmp){
        if(!root) return;
        if(!root->left && !root->right){
            int tmpSum = root->val;
            for_each(tmp.begin(), tmp.end(), [&](const int num){
                tmpSum += num;
            });
            
            if(tmpSum == sum){
                tmp.push_back(root->val);
                ans.push_back(tmp);
            }
            
            return;
        }
        
        
        if(root->left){
            tmp.push_back(root->val);
            dfs(root->left,sum,ans,tmp);
            tmp.pop_back();
        }
        if(root->right){
            tmp.push_back(root->val);
            dfs(root->right,sum,ans,tmp);
            tmp.pop_back();
        }
    }
};
