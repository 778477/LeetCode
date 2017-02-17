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
#include <unordered_map>
#include <algorithm>
#include <functional>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;


/**
 
 133. Clone Graph
 
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 
 OJ's undirected graph serialization:
 Nodes are labeled uniquely.
 
 We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 
 First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 Second node is labeled as 1. Connect node 1 to node 2.
 Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 Visually, the graph looks like the following:
 
    1
   / \
  /   \
 0 --- 2
      / \
      \_/
 
 
 */

/**
 
 图的深拷贝
 
 12 / 12 test cases passed.
 Status: Accepted
 Runtime: 36 ms
 
 */


//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        UndirectedGraphNode *cloneNewNode = new UndirectedGraphNode(node->label);
        map<int,UndirectedGraphNode *> table;
        queue<UndirectedGraphNode *> Q;
        
        Q.push(node);
        table[node->label] = cloneNewNode;
        while(!Q.empty()){
            UndirectedGraphNode *nowNode = Q.front();
            UndirectedGraphNode *cloneNode = table[nowNode->label];
            Q.pop();
            
            for(UndirectedGraphNode *neigbor : nowNode->neighbors){
                if(table.find(neigbor->label) == table.end()){
                    UndirectedGraphNode *clone_neighbor = new UndirectedGraphNode(neigbor->label);
                    table[neigbor->label] = clone_neighbor;
                    Q.push(neigbor);
                }
                cloneNode->neighbors.push_back(table[neigbor->label]);
            }
            
        }
        return table[node->label];
    }
};


int main(){
    
    return 0;
}
