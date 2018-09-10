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
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;


/**
 785. Is Graph Bipartite?
 
 Given an undirected graph, return true if and only if it is bipartite.
 
 Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
 
 The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.
 
 Example 1:
 Input: [[1,3], [0,2], [1,3], [0,2]]
 Output: true
 Explanation:
 The graph looks like this:
 0----1
 |    |
 |    |
 3----2
 We can divide the vertices into two groups: {0, 2} and {1, 3}.
 Example 2:
 Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
 Output: false
 Explanation:
 The graph looks like this:
 0----1
 | \  |
 |  \ |
 3----2
 We cannot find a way to divide the set of nodes into two independent subsets.
 
 
 Note:
 
 graph will have length in range [1, 100].
 graph[i] will contain integers in range [0, graph.length - 1].
 graph[i] will not contain i or duplicate values.
 The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
 
 */

/**
 
 78 / 78 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 
 */

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c){
        if(color[node] != -1){
            return color[node] == c;
        }
        
        color[node] = c;
        
        for(int next : graph[node]){
            if(!dfs(graph, color, next, c^1)){
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(101,-1);
        
        for(auto node = 0; node < graph.size(); ++node){
            if(color[node] == -1 && !dfs(graph, color, node, 0)){
                return false;
            }
            
            for(auto edge : graph[node]){
                if(color[node] == color[edge]){
                    return false;
                }
            }
            
        }
        
        return true;
    }
};


int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    Solution solve;
    vector<vector<int>> graph = {{4},{},{4},{4},{0,2,3}};
    cout<<solve.isBipartite(graph)<<endl;
    
    return 0;
}

