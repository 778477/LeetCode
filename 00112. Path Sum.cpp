
//	Accepted	14 ms	cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag = false;
        
        if(root){
            dfs(root,&flag,0,sum);
        }
    
        return flag;
    }
    
    void dfs(TreeNode* root,bool *flag,int tmpSum,int sum){
        if(*flag) return;
        
        if(!root->left && !root->right){
            if(tmpSum + root->val == sum){
                *flag = true;
                return ;
            }
        }
        
        if(root->left){
            dfs(root->left,flag,tmpSum + root->val, sum);
        }
        
        if(root->right){
            dfs(root->right,flag,tmpSum + root->val, sum);
        }
        
    }
};
