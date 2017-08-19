/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 2 years, 2 months ago
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode *> S;
        S.push(root);
        
        while(!S.empty()){
            TreeNode *node = S.top();
            S.pop();
            
            if(node->left){
                S.push(node->left);
            }
            if(node->right){
                S.push(node->right);
            }
            
            swap(node->left, node->right);
        }
        return root;
    }
    
    
    void dfs(TreeNode *root,vector<int>& array){
        if(!root) return;
        dfs(root->left, array);
        array.push_back(root->val);
        dfs(root->right, array);
    }
    
    void output(const vector<int>& array){
        cout<<"output array all the elements:"<<endl;
        for_each(array.begin(), array.end(), [&](const int num){
            cout<<num<<endl;
        });
    }
};
