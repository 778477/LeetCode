//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;
/*
 
 114. Flatten Binary Tree to Linked List
 Total Accepted: 104539
 Total Submissions: 315093
 Difficulty: Medium
 Contributors: Admin
 Given a binary tree, flatten it to a linked list in-place.
 
 For example,
 Given
 
     1
    / \
   2   5
  / \   \
 3   4   6
 The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 
 */


/*
 
 225 / 225 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 Submitted: 0 minutes ago
 
 
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
    void flatten(TreeNode* root) {
        if(!root) return ;
        
        queue<int> bucket;
        dfs(root,bucket);
        
        
        root->val = bucket.front();
        root->left = root->right = NULL;
        bucket.pop();
        
        TreeNode* tmp = root;
        
        while(!bucket.empty()){
            tmp->right = new TreeNode(bucket.front());
            bucket.pop();
            tmp = tmp->right;
        }
    }
    
    void dfs(TreeNode* root,queue<int>& bucket){
        if(!root) return ;
        bucket.push(root->val);
        dfs(root->left,bucket);
        dfs(root->right,bucket);
    }
};


