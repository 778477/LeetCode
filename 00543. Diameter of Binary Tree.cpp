//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/**
 
 543. Diameter of Binary Tree
 
 Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 
 Example:
 Given a binary tree
     1
    / \
   2   3
  / \
 4   5
 Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 
 Note: The length of path between two nodes is represented by the number of edges between them.
 
 */

/**
 
 
 106 / 106 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */




//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* root,int* ans){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        *ans = max(*ans,left+right+1);

        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        
        dfs(root,&ans);
        
        return max(0,ans-1);
    }
};



// [4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]
int main(){
    
    TreeNode *root = new TreeNode(1);
    //    root->left = new TreeNode(2);
    //    root->right = new TreeNode(3);
    //    root->left->left = new TreeNode(4);
    //    root->left->right = new TreeNode(5);
    //
    //    root->left->left->left = new TreeNode(6);
    //    root->left->right->right = new TreeNode(7);
    
    Solution solve;
    
    printf("%d\n",solve.diameterOfBinaryTree(root));
    
    return 0;
}
