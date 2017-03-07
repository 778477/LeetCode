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
 
 230. Kth Smallest Element in a BST
 
 Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 
 Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 
 */


/**
 中序遍历，生成有序数组之后，访问下标 k-1 元素
 
 
 91 / 91 test cases passed.
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        dfs(root,nums);
        return nums[k - 1];
    }
    void dfs(TreeNode *root,vector<int>& nums){
        if(!root) return ;
        
        dfs(root->left,nums);
        nums.push_back(root->val);
        dfs(root->right,nums);
    }
    
};




