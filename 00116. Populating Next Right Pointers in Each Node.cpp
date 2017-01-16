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
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;


/*
 116. Populating Next Right Pointers in Each Node
 Total Accepted: 114088
 Total Submissions: 309686
 Difficulty: Medium
 Contributors: Admin
 Given a binary tree
 
 struct TreeLinkNode {
 TreeLinkNode *left;
 TreeLinkNode *right;
 TreeLinkNode *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 
 Note:
 
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
 1
 /  \
 2    3
 / \  / \
 4   5 6  7
 
 After calling your function, the tree should look like:
 1 -> NULL
 /  \
 2 -> 3 -> NULL
 / \  / \
 4->5->6->7 -> NULL
 
 **/


/*
 
 14 / 14 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 Submitted: 0 minutes ago
 
 **/

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
    void connect(TreeLinkNode *root) {
        if(!root) return ;
        TreeLinkNode *tmp = root;
        TreeLinkNode *rightNode = NULL;
        while(tmp){
            if(tmp->left && tmp->right){
                if(rightNode){
                    rightNode->next = tmp->left;
                }
                tmp->left->next = tmp->right;
            }
            rightNode = tmp->right;
            tmp = tmp->next;
        }
        connect(root->left);
    }
};

