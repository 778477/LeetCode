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
#include <unordered_map>
#include <string>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 530. Minimum Absolute Difference in BST
 
 Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
 
 Example:
 
 Input:
 
 1
  \
   3
  /
 2
 
 Output:
 1
 
 Explanation:
 The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 Note: There are at least two nodes in this BST.
 
 */


/**
 中序遍历，生成有序数组之后，再查看计算相邻item's absolute difference
 
 186 / 186 test cases passed.
 Status: Accepted
 Runtime: 26 ms
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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        
        vector<int> vals;
        dfs(root,vals);
        
        if(vals.size() < 2) return -1;
        
        for(unsigned i=1;i<vals.size();i++){
            ans = min(abs(vals[i] - vals[i-1]),ans);
        }
        
        return ans;
    }
private:
    void dfs(const TreeNode* root,vector<int>& vals){
        if(!root) return ;
        dfs(root->left,vals);
        vals.push_back(root->val);
        dfs(root->right, vals);
    }
};


int main(){
    Solution solve;
    
    TreeNode *node = new TreeNode(236);
    node->left = new TreeNode(104);
    node->right = new TreeNode(701);
    node->left->right = new TreeNode(227);
    node->right->right = new TreeNode(911);
    
    cout<<solve.getMinimumDifference(node)<<endl;
    return 0;
    
}



