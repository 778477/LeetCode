//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 332. Reconstruct Itinerary
 
 Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
 
 Note:
 1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 2. All airports are represented by three capital letters (IATA code).
 3. You may assume all tickets form at least one valid itinerary.
 
 
 Example 1:
 tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 
 Example 2:
 tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 
 */

/*
 
 80 / 80 test cases passed.
 Status: Accepted
 Runtime: 52 ms
 
 */

class Solution {
    public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        
        build(tickets);
        
        vector<string> tmp;
        tmp.push_back("JFK");
        dfs("JFK",tmp,ans,tickets.size()+1);
        
        return ans;
    }
    
    void build(vector<pair<string, string>> tickets){
        table.clear();
        vis.clear();
        for(pair<string, string> t : tickets){
            table[t.first].push_back(t.second);
        }
        
        for(map<string,vector<string>>::iterator iter = table.begin(); iter !=table.end(); iter++){
            sort(iter->second.begin(), iter->second.end());
        }
    }
    
    bool dfs(string from,vector<string>& tmp,vector<string>& ans, unsigned long cnt){
        if(tmp.size() == cnt){
            ans = tmp;
            return true;
        }
        
        for(auto i = 0;i<table[from].size();i++){
            string path = from + table[from][i] + to_string(i);
            if(!vis[path]){
                vis[path] = true;
                tmp.push_back(table[from][i]);
                if(dfs(table[from][i],tmp,ans,cnt)) return true;
                tmp.pop_back();
                vis[path] = false;
            }
        }
        
        return false;
    }
    
    private:
    map<string,bool> vis;
    map<string,vector<string>> table;
};


int main(){
    
    freopen("/Users/guomiaoyou/Documents/778477/leetCode/leetCode/in.txt", "r", stdin);
    vector<pair<string, string>> tickets;
    string buf;
    while(cin>>buf){
        tickets.push_back(make_pair(buf.substr(0,3), buf.substr(3,3)));
    }
    
    Solution solve;
    
    
    
    vector<string> ans = solve.findItinerary(tickets);
    
    for(string t : ans){
        cout<<t<<endl;
    }
    
    return 0;
}
