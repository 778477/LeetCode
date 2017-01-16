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
 117. Populating Next Right Pointers in Each Node II
 Total Accepted: 81586
 Total Submissions: 243571
 Difficulty: Hard
 Contributors: Admin
 Follow up for problem "Populating Next Right Pointers in Each Node".
 
 What if the given tree could be any binary tree? Would your previous solution still work?
 
 Note:
 
 You may only use constant extra space.
 For example,
 Given the following binary tree,
     1
    /  \
   2    3
  / \    \
 4   5    7
 After calling your function, the tree should look like:
      1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \    \
 4-> 5 -> 7 -> NULL
 
 
 **/


/*
 
 
 61 / 61 test cases passed.
 Status: Accepted
 Runtime: 33 ms
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
        TreeLinkNode *leftNode = NULL;
        while(tmp){
            if(tmp->left && tmp->right){
                if(rightNode){
                    rightNode->next = tmp->left;
                }
                tmp->left->next = tmp->right;
                rightNode = tmp->right;
            } else if(tmp->left || tmp->right){
                if(rightNode){
                    rightNode->next = tmp->left ? tmp->left : tmp->right;
                }
                rightNode = tmp->left ? tmp->left : tmp->right;
            }
            
            
            if(!leftNode){
                leftNode = tmp->left ? tmp->left : tmp->right;
            }
            tmp = tmp->next;
        }
        connect(leftNode);
    }
};

