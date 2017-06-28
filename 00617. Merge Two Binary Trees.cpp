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
 
 617. Merge Two Binary Trees
 DescriptionHintsSubmissionsSolutions
 Discuss   Editorial Solution Pick One
 Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
 
 You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.
 
 Example 1:
 Input:
	Tree 1                     Tree 2
        1                         2
       / \                       / \
      3   2                     1   3
     /                           \   \
    5                             4   7
 Output:
 Merged tree:
        3
       / \
      4   5
     / \   \
    5   4   7
 Note: The merging process must start from the root nodes of both trees.
 
 */

/**
 
 183 / 183 test cases passed.
 Status: Accepted
 Runtime: 48 ms
 
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return NULL;
        if(!t1){
            t1 = new TreeNode(t2->val);
            t1->left = mergeTrees(NULL, t2->left);
            t1->right = mergeTrees(NULL, t2->right);
            return t1;
        } else if(!t2){
            
        } else{
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
        }
        
        return t1;
    }
};

//[1,3,2,5]
//[2,1,3,null,4,null,7]

//[3,4,5,5,4,null,7]

void output(TreeNode *root){
    if(!root){
        printf("null,");
        return ;
    } else {
        printf("%d,",root->val);
    }
    
    output(root->left);
    output(root->right);
    
}

int main(){
    
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);
    
    TreeNode *t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);
    
    Solution solve;
    
    TreeNode *ans = solve.mergeTrees(t1, t2);
    
    output(ans);
    printf("\n");
    
    
    return 0;
}
