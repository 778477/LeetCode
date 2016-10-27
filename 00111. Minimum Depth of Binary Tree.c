
//Accepted	4 ms	c
void dfs(struct TreeNode* node,int step,int *ans){
    if(!node) return ;
    if(!(node->left) && !(node->right)){
        *ans = *ans < step ? *ans : step;
        return ;
    }
    
    dfs(node->left,step+1,ans);
    dfs(node->right,step+1,ans);
}

int minDepth(struct TreeNode* root) {
    int ans = INT_MAX;
    dfs(root,1,&ans);
    return ans == INT_MAX ? 0 : ans;
}
