
//Accepted	116 ms	cpp
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(postorder.size() == 0) return NULL;

        return buildTree2(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

    TreeNode* buildTree2(vector<int>& inorder,int inBeg,int inEnd,vector<int>& postorder,int postBeg,int postEnd)
    {
        if(postBeg > postEnd) return NULL;

        int rtVal = postorder[postEnd];

        int index;
        for(int i=inBeg;i<=inEnd;i++)
        {
            if(inorder[i] == rtVal)
            {
                index = i;
                break;
            }
        }

        int len = index - inBeg;
        TreeNode* root = new TreeNode(rtVal);
        root->left = buildTree2(inorder,inBeg,index-1,postorder,postBeg,postBeg+len-1);
        root->right = buildTree2(inorder,index+1,inEnd,postorder,postBeg+len,postEnd-1);
        return root;
    }
};
