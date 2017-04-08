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
 
 199. Binary Tree Right Side View
 
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 
 For example:
 Given the following binary tree,
    1            <---
  /   \
 2     3         <---
  \     \
   5     4       <---
 You should return [1, 3, 4].
 
 Credits:
 Special thanks to @amrsaqr for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 Hide Tags Tree Depth-first Search Breadth-first Search
 Show Similar Problems
 
 
 */


/**
 
 
 Tree/Depth-first Search/Breadth-first Search
 
 
 210 / 210 test cases passed.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        bfs(root,ans);
        return ans;
    }
    
    void bfs(TreeNode *root,vector<int> &ans){
        queue<TreeNode *> Q;
        if(root) Q.push(root);
        
        while(!Q.empty()){
            int size = (int)Q.size();
            
            while(size){
                TreeNode *now = Q.front();
                Q.pop();
                if(now->left) Q.push(now->left);
                if(now->right) Q.push(now->right);
                if(size == 1) ans.push_back(now->val);
                --size;
            }
            
        }
        
    }
};

int main(){
    return 0;
}

