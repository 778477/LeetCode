//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

/**
 
 404. Sum of Left Leaves
 
 Find the sum of all left leaves in a given binary tree.
 
 Example:
 
    3
   / \
  9  20
    /  \
   15   7
 
 There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 
 
 */


/**
 
 102 / 102 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root,&ans,false);
        return ans;
    }
    
    void dfs(TreeNode *root, int *ans,bool isLeft){
        if(!root) return ;
        if(!root->left && !root->right && isLeft){
            *ans += root->val;
        }
        
        dfs(root->left, ans, true);
        dfs(root->right, ans, false);
    }
};

int main(){
    
    
    return 0;
}
