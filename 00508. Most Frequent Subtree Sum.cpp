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
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 508. Most Frequent Subtree Sum
 
 Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
 
 Examples 1
 Input:
 
     5
   /  \
  2   -3
 return [2, -3, 4], since all the values happen only once, return all of them in any order.
 Examples 2
 Input:
 
    5
  /  \
 2   -5
 return [2], since 2 happens twice, however -5 only occur once.
 Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
 
 
 */


/**
 
 Tree / Hash Table
 
 61 / 61 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 
 */



//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


typedef pair<int, unsigned> frequent; // val : count
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        map<int,unsigned> countTable;
        vector<frequent> array;
        subTreeSum(root,countTable);
        
        for(map<int,unsigned>::iterator iter = countTable.begin(); iter != countTable.end(); ++iter){
            array.push_back(make_pair(iter->first, iter->second));
        }
        
        sort(array.begin(), array.end(), [&](const frequent a, const frequent b){
            return a.second > b.second;
        });
        
        unsigned maxCount = 0;
        
        for(frequent f : array){
            if(f.second >= maxCount){
                maxCount = f.second;
                ans.push_back(f.first);
            }
        }
        
        return ans;
    }
    
    int subTreeSum(TreeNode *root,map<int,unsigned>& table){
        int sum = 0;
        if(!root) return sum;
        sum = root->val + subTreeSum(root->left,table) + subTreeSum(root->right,table);
        ++table[sum];
        return sum;
    }
    
};


int main(){
    
    return 0;
}
