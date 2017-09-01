//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 257. Binary Tree Paths
 
 Given a binary tree, return all root-to-leaf paths.
 
 For example, given the following binary tree:
 
    1
  /   \
 2     3
  \
   5
 All root-to-leaf paths are:
 
 ["1->2->5", "1->3"]
 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 
 
 */


/**
 
 209 / 209 test cases passed.
 Status: Accepted
 Runtime: 9 ms
 
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
    void dfs(TreeNode *root, string& str, vector<string>& strs){
        if(!root) return ;
        string now = str + to_string(root->val);
        
        if(!root->left && !root->right){
            strs.push_back(now);
            return ;
        }
        
        if(root->left){
            string leftStr = now + "->";
            dfs(root->left, leftStr, strs);
        }
        
        if(root->right){
            string rightStr = now + "->";
            dfs(root->right, rightStr, strs);
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str = "";
        dfs(root, str, ans);
        
        return ans;
    }
};


int main(){
    
    
    return 0;
}
