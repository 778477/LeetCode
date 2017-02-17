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


/**
 
 513. Find Bottom Left Tree Value
 
 Given a binary tree, find the leftmost value in the last row of the tree.
 
 Example 1:
 Input:
 
   2
  / \
 1   3
 
 Output:
 1
 Example 2:
 Input:
 
       1
      / \
     2   3
    /   / \
   4   5   6
  /
 7
 
 Output:
 7
 
 */

/**
 
 74 / 74 test cases passed.
 Status: Accepted
 Runtime: 18 ms
 
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
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        
        queue<TreeNode *> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int size = (int)Q.size();
            ans = Q.front()->val;
            while(size--){
                TreeNode *node = Q.front();
                Q.pop();
                
                if(node->left){
                    Q.push(node->left);
                }
                
                if(node->right){
                    Q.push(node->right);
                }
            }
            
        }
        
        return ans;
    }
};


int main(){
    
    return 0;
}
