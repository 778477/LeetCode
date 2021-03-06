
//	Accepted	4 ms	c

bool compareNode(struct TreeNode *left, struct TreeNode *right){
    if(!left && !right) return true;
    if(left && right){
        if(left->val != right->val) return false;
        
        return compareNode(left->left, right->right) && compareNode(left->right, right->left);
    }
    
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if(!root) return true;
    
    return compareNode(root->left,root->right);
}
