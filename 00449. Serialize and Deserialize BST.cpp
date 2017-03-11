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
 
 449. Serialize and Deserialize BST
 
 Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 
 Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
 
 The encoded string should be as compact as possible.
 
 Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 
 
 */


/**
 
 Tree
 
 serialize
 tree => preOrder
 deserialize
 preOrder => tree
 
 
 62 / 62 test cases passed.
 Status: Accepted
 Runtime: 135 ms
 
 */




//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream preStream;
        
        preOrder(root, preStream);
        return preStream.str();
    }
    
    void preOrder(TreeNode* root, stringstream& stream){
        if(!root) return;
        
        stream<<root->val<<",";
        preOrder(root->left, stream);
        preOrder(root->right, stream);
    }
    
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preOrder;
        
        unsigned pos = 0;
        for(unsigned i=0;i<data.length();i++){
            if(data[i] == ','){
                preOrder.push_back(stoi(data.substr(pos,i-pos)));
                pos = i+1;
            }
        }
        
        return buildTree(preOrder,0,(int)preOrder.size()-1);
    }
    
    TreeNode* buildTree(const vector<int> preOrder,int begin,int end){
        if(begin > end) return NULL;
        
        int idx = end;
        
        while(preOrder[idx] > preOrder[begin]) --idx;
        
        TreeNode *root = new TreeNode(preOrder[begin]);
        root->left = buildTree(preOrder, begin+1, idx);
        root->right = buildTree(preOrder, idx+1, end);
        return root;
    }
};



int main(){
    
    Codec code;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    
    string ans = code.serialize(root);
    cout<<ans<<endl;
    
    code.deserialize(ans);
    
    
    
    return 0;
}
