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
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/**
 
 
 637. Average of Levels in Binary Tree
 
 
 Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
 
 Example 1:
 Input:
   3
  / \
 9  20
   /  \
  15   7
 Output: [3, 14.5, 11]
 Explanation:
 The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
 Note:
 The range of node's value is in the range of 32-bit signed integer.
 
 */


/**
 
 广度优先搜索遍历即可
 64 / 64 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> Q;
        if(root) Q.push(root);
        
        while(!Q.empty()){
            long long tmp = Q.size(),size = tmp;
            double sum = 0;
            while(tmp--){
                sum += Q.front()->val;
                
                if(Q.front()->left){
                    Q.push(Q.front()->left);
                }
                
                if(Q.front()->right){
                    Q.push(Q.front()->right);
                }
                
                Q.pop();
            }
            
            ans.push_back(sum*1.0 / size);
        }
        
        return ans;
    }
};


int main(){
    Solution solve;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<double> ans = solve.averageOfLevels(root);
    
    for(double val : ans){
        cout<<val<<endl;
    }
}



