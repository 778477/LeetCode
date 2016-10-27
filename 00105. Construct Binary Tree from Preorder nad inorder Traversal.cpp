
//Accepted	124 ms	cpp
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0) return NULL;

        return buildTree2(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode *buildTree2(vector<int>& preorder,int preBeg,int preEnd,vector<int>& inorder,int inBeg,int inEnd)
    {
        if(inBeg > inEnd) return NULL;

        int rtVal = preorder[preBeg];
        int index ;

        for(int i=inBeg;i<=inEnd;i++)
        {
            if(rtVal == inorder[i])
            {
                index = i;
                break;
            }
        }

        int len = index - inBeg;
        TreeNode *root = new TreeNode(rtVal);
        root->left = buildTree2(preorder,preBeg+1,preBeg+len,inorder,inBeg,index-1);
        root->right = buildTree2(preorder,preBeg+len+1,preEnd,inorder,index+1,inEnd);

        return root;
    }
};
