//
//  main.cpp
//  whiteBorad-leetcode
//
//  Created by 郭妙友 on 2018/3/30.
//  Copyright © 2018年 郭妙友. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;


/**
 
 46 / 46 test cases passed.
 Status: Accepted
 Runtime: 14 ms
 
 */
class Solution {
    class State{
        public:
        int cover,head;
        State(int c,int h):cover(c),head(h){}
    };
    public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int ans = 0;
        const auto GraphNodeCount = graph.size();
        vector<vector<int>> dist(1 << GraphNodeCount,vector<int>(GraphNodeCount, 0x3fff3fff));
        queue<State *> Q;
        
        for(auto i = 0;i<GraphNodeCount; ++i){
            dist[1 << i][i] = 0;
            Q.push(new State(1<<i,i));
        }
        
        
        while(!Q.empty()){
            State *now = Q.front();
            Q.pop();
            
            int step = dist[now->cover][now->head];
            while(now->cover == (1<<GraphNodeCount) - 1){
                return step;
            }
            
            
            for(auto i=0; i<graph[now->head].size(); ++i){
                auto visNode = graph[now->head][i];
                
                if(dist[now->cover | (1<<visNode)][visNode] > step + 1){
                    dist[now->cover | (1<<visNode)][visNode] = step + 1;
                    Q.push(new State(now->cover | (1<<visNode),visNode));
                }
            }
        }
        
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solve;
    vector<vector<int>> graph;
    graph.push_back({1});
    graph.push_back({0,2,4});
    graph.push_back({1,3,4});
    graph.push_back({2});
    graph.push_back({1,2});
    
    cout<<solve.shortestPathLength(graph)<<endl;
    
    return 0;
}
