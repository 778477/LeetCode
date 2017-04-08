//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 236. Lowest Common Ancestor of a Binary Tree
 
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 
 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 
         _______3_______
        /               \
     ___5___          ___1___
    /       \        /       \
    6       2       0         8
  /  \
 7   4
 For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 
 Subscribe to see which companies asked this question.
 
 
 
 */


/**
 
 31 / 31 test cases passed.
 Status: Accepted
 Runtime: 13 ms
 
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p == q) return p;
        if(!p || !q) return NULL;
        if(p && (p->left == q || p->right == q)) return p;
        if(q && (q->left == p || q->right == p)) return q;
        
        vector<TreeNode *> pPath;
        vector<TreeNode *> qPath;
        
        dfs(root,p,pPath);
        dfs(root,q,qPath);
        if(pPath.size() == 0 || qPath.size() == 0) return NULL;
        
        auto pidx = pPath.size() > qPath.size() ? pPath.size() - qPath.size() : 0;
        auto qidx = qPath.size() > pPath.size() ? qPath.size() - pPath.size() : 0;
        
        while (pPath[pidx] != qPath[qidx]) {
            pidx++,qidx++;
        }
        
        
        return pPath[pidx];
    }
    
    bool dfs(TreeNode *root, TreeNode* targer,vector<TreeNode *> &path){
        if(!root || !targer) return false;
        if(root == targer) {
            path.push_back(targer);
            return true;
        }
        
        if(dfs(root->left,targer,path) || dfs(root->right,targer,path)){
            path.push_back(root);
            return true;
        }
        
        return false;
    }
};

int main(){
    
    Solution solve;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    cout<<solve.lowestCommonAncestor(root, root->left->left, root->right->right)->val<<endl;
    
    
    return 0;
}

