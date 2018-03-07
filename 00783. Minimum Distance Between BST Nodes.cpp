
//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 783. Minimum Distance Between BST Nodes
 
 Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
 
 Example :
 
 Input: root = [4,2,6,1,3,null,null]
 Output: 1
 Explanation:
 Note that root is a TreeNode object, not an array.
 
 The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
 
      4
    /   \
   2      6
  / \
 1   3
 
 while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
 Note:
 
 The size of the BST will be between 2 and 100.
 The BST is always valid, each node's value is an integer, and each node's value is different.
 
 */

/**
 
 
 45 / 45 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 根据BST 特性，中序遍历是有序序列，而最小差值的数字对 一定是有序序列中相邻
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    void dfs(TreeNode* root,vector<int>& array){
        if(!root) return ;
        
        dfs(root->left,array);
        array.push_back(root->val);
        dfs(root->right, array);
        
    }
    int minDiffInBST(TreeNode* root) {
        int ans = root->val;
        
        vector<int> array;
        dfs(root,array);
        
        for(int i=1;i<array.size();++i){
            ans = min(ans, array[i] - array[i-1]);
        }
        
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    Solution solve;
    cout<<solve.minDiffInBST(root)<<endl;
    
    return 0;
}
