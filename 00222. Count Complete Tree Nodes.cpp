//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 222. Count Complete Tree Nodes
 
 Given a complete binary tree, count the number of nodes.
 
 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 
 */

/**
 
 18 / 18 test cases passed.
 Status: Accepted
 Runtime: 169 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int leftLevel = 1,rightLevel = 1;
        TreeNode *tmp = root;
        while(tmp->left){
            ++leftLevel;
            tmp = tmp->left;
        }
        tmp = root;
        while(tmp->right){
            ++rightLevel;
            tmp = tmp->right;
        }
        
        if(leftLevel == rightLevel) return pow(2,leftLevel) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


int main(int argc, const char * argv[]) {
    
    
    return 0;
}
