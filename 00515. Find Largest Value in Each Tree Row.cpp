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
 
 515. Find Largest Value in Each Tree Row
 
 You need to find the largest value in each row of a binary tree.
 
 Example:
 Input:
 
     1
    / \
   3   2
  / \   \
 5   3   9
 
 Output: [1, 3, 9]
 
 */

/**
 
 78 / 78 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode *> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int size = (int)Q.size();
            int max = Q.front()->val;
            while(size--){
                TreeNode *node = Q.front();
                max = node->val > max ? node->val : max;
                Q.pop();
                
                if(node->left){
                    Q.push(node->left);
                }
                
                if(node->right){
                    Q.push(node->right);
                }
            }
            ans.push_back(max);
        }
        
        return ans;
    }
};


int main(){
    
    return 0;
}
