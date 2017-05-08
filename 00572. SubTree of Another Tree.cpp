//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
 
 572. Subtree of Another Tree
 
 Total Accepted: 2035
 Total Submissions: 4680
 Difficulty: Easy
 Contributors:
 xljob
 Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
 
 Example 1:
 Given tree s:
 
     3
    / \
   4   5
  / \
 1   2
 Given tree t:
   4
  / \
 1   2
 Return true, because t has the same structure and node values with a subtree of s.
 Example 2:
 Given tree s:
 
       3
      / \
     4   5
    / \
   1   2
  /
 0
 Given tree t:
   4
  / \
 1   2
 Return false.
 Subscribe to see which companies asked this question.
 
 */

/*
 
 176 / 176 test cases passed.
 Status: Accepted
 Runtime: 39 ms
 
 */

/**
 case 1:
 [3,4,1,2,null,null,3]
 [3,2,3]
 
 case 2:
 [1,1]
 [1]
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
    bool isSubTreeWithParent(TreeNode *s,TreeNode *t,bool isParent){
        if(!s && !t) return true;
        if(s && !t) return false;
        if(!s && t) return false;
        
        bool flag = false;
        if(s->val == t->val){
            flag = isSubTreeWithParent(s->left, t->left, true) && isSubTreeWithParent(s->right, t->right, true);
        }
        
        if(!flag && isParent) return false;
        
        return flag || isSubTreeWithParent(s->left, t, false) || isSubTreeWithParent(s->right, t, false);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSubTreeWithParent(s, t, false);
    }
};


int main(){
    
    return 0;
}
