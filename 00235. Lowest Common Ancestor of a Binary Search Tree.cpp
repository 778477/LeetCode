/**
 Status: Accepted
 Runtime: 24 ms
 Submitted: 1 year, 3 months ago
*/
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    bool p_onRight = p->val >= root->val;
    bool q_onRight = q->val >= root->val;
    
    if((p_onRight && !q_onRight) || (q_onRight && !p_onRight)){
        return root;
    }
    
    if(!p_onRight && !q_onRight){
        return lowestCommonAncestor(root->left, p, q);
    }
    
    if(p_onRight && q_onRight){
        if(p->val == root->val) return p;
        if(q->val == root->val) return q;
        return lowestCommonAncestor(root->right, p, q);
    }
    
    return NULL;
}
