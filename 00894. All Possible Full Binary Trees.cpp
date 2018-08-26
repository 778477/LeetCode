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
 
 894. All Possible Full Binary Trees
 
 A full binary tree is a binary tree where each node has exactly 0 or 2 children.
 
 Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.
 
 Each node of each tree in the answer must have node.val = 0.
 
 You may return the final list of trees in any order.
 
 
 Example 1:
 
 Input: 7
 Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 Explanation:
 
 
 
 Note:
 
 1 <= N <= 20
 
 */

/**
 
 
 20 / 20 test cases passed.
 Status: Accepted
 Runtime: 144 ms
 
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, vector<TreeNode *>> memo;
    
    Solution(){
        memo[0] = {};
        memo[1] = {new TreeNode(0)};
    }
    
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0){
            return {};
        }
        
        if(memo.find(N) == memo.end()){
            vector<TreeNode *> ans;
            for(auto i=0;i<N;i++){
                vector<TreeNode *> leftTree = allPossibleFBT(i);
                vector<TreeNode *> rightTree = allPossibleFBT(N-1-i);
                
                for(TreeNode *left : leftTree){
                    for(TreeNode *right : rightTree){
                        TreeNode *r = new TreeNode(0);
                        r->left = left;
                        r->right = right;
                        ans.push_back(r);
                    }
                }
                
            }
            memo[N] = ans;
        }
        
        return memo[N];
    }
};

int main(){
    
    
    Solution solve;
    vector<TreeNode *> trees = solve.allPossibleFBT(5);
    
    
    
    return 0;
}


