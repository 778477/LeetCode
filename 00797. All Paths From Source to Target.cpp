//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 797. All Paths From Source to Target
 
 Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
 
 The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
 
 Example:
 Input: [[1,2], [3], [3], []]
 Output: [[0,1,3],[0,2,3]]
 Explanation: The graph looks like this:
 
 0--->1
 |    |
 v    v
 2--->3
 
 There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 Note:
 
 The number of nodes in the graph will be in the range [2, 15].
 You can print different paths in any order, but you should keep the order of nodes inside one path.
 
 
 */


/**
 
 26 / 26 test cases passed.
 Status: Accepted
 Runtime: 114 ms
 
 */


class Solution {
    
public:
    
    void dfs(int star,vector<int>& temp,const vector<vector<int>> g,vector<vector<bool>>& v,vector<vector<int>>& ans){
        
        if(star == g.size() - 1){
            ans.push_back(vector<int>(temp));
            return ;
        }
        
        for(int i = 0;i<g[star].size(); ++i){
            
            int next = g[star][i];
            if(!v[star][next]){
                v[star][next] = true;
                temp.push_back(next);
                
                dfs(next,temp,g,v,ans);
                
                temp.pop_back();
                v[star][next] = false;
            }
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        vector<vector<bool>> vis(graph.size(),vector<bool>(graph.size(),false));
        
        vector<int> feetLog;
        feetLog.push_back(0);
        
        dfs(0, feetLog, graph, vis, ans);
        
        return ans;
        
    }
};

int main(){
    Solution solve;
    
    vector<vector<int>> graph;
    graph.push_back({1,2});
    graph.push_back({3});
    graph.push_back({3});
    graph.push_back({});
    
    vector<vector<int>> ans = solve.allPathsSourceTarget(graph);
    
    for (vector<int> path : ans) {
        for(int n : path){
            cout<<n<<",";
        }
        cout<<endl;
    }
    return 0;
}
