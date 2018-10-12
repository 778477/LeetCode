//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;



/**
 
 919. Complete Binary Tree Inserter
 
 A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
 
 Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:
 
 CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
 CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
 CBTInserter.get_root() will return the head node of the tree.
 
 
 Example 1:
 
 Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
 Output: [null,1,[1,2]]
 Example 2:
 
 Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
 Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 
 
 Note:
 
 The initial given tree is complete and contains between 1 and 1000 nodes.
 CBTInserter.insert is called at most 10000 times per test case.
 Every value of a given or inserted node is between 0 and 5000.
 
 
 */

/**
 
 83 / 83 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
 */


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class CBTInserter {
public:
    vector<TreeNode *> nodes;
    CBTInserter(TreeNode* root) {
        nodes.clear();
        
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            auto size = q.size();
            while(size > 0){
                TreeNode *now = q.front();
                q.pop();
                nodes.push_back(now);
                
                if(now->left){
                    q.push(now->left);
                }
                
                if(now->right){
                    q.push(now->right);
                }
                --size;
            }
        }
        
    }
    
    int insert(int v) {
        auto idx = (nodes.size() - 1)/2;
        TreeNode *next = new TreeNode(v);
        nodes.push_back(next);
        nodes[idx]->left ? nodes[idx]->right = next : nodes[idx]->left = next;
        return nodes[idx]->val;
    }
    
    TreeNode* get_root() {
        return nodes[0];
    }
};


int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    return 0;
}

