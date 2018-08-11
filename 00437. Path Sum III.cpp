//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 
 437. Path Sum III
 
 You are given a binary tree in which each node contains an integer value.
 
 Find the number of paths that sum to a given value.
 
 The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
 
 The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
 
 Example:
 
 root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 
 10
 /  \
 5   -3
 / \    \
 3   2   11
 / \   \
 3  -2   1
 
 Return 3. The paths that sum to 8 are:
 
 1.  5 -> 3
 2.  5 -> 2 -> 1
 3. -3 -> 11
 
 Note:
 
 2 <= piles.length <= 500
 piles.length is even.
 1 <= piles[i] <= 500
 sum(piles) is odd.
 
 */

/**
 
 
 126 / 126 test cases passed.
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
    void dfs(TreeNode *root,int& ans,int tmpSum,bool use_par){
        
        if(!root) return ;
        
        if(tmpSum - root->val == 0){
            ++ans;
        }
        
        dfs(root->left,ans,tmpSum - root->val, true);
        dfs(root->right,ans,tmpSum - root->val, true);
        
        if(!use_par){
            dfs(root->left,ans,tmpSum, false);
            dfs(root->right, ans, tmpSum, false);
        }
        
    }
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        
        dfs(root,ans,sum,false);
        
        return ans;
        
    }
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();


int main(){
    
    Solution solve;
    TreeNode *root = new TreeNode(1);
    TreeNode *tmp = root;
    for(int i=2;i<6;++i){
        tmp->right = new TreeNode(i);
        tmp = tmp->right;
    }
    
    cout<<solve.pathSum(root, 3)<<endl;
    
    return 0;
}


