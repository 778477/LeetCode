
//Accepted	84 ms	cpp
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0) return NULL;

        if(num.size() == 1)
        {
            TreeNode *root = new TreeNode(num[0]);
            return root;
        }

        return array2BST(num,0,num.size()-1);
    }

    TreeNode* array2BST(vector<int>& num,int i,int j)
    {
        if(i == j)
        {
            TreeNode* root = new TreeNode(num[i]);
            return root;
        }
        int mid = i+((j-i)>>1);
        TreeNode* root = new TreeNode(num[mid]);

        if(mid != i)
            root->left = array2BST(num,i,mid-1);

        root->right = array2BST(num,mid+1,j);
        return root;
    }
};

