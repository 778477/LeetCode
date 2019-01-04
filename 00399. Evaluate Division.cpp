//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//


#include <iostream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

/**
 
 399. Evaluate Division
 DescriptionHintsSubmissionsDiscussSolution
 Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
 
 Example:
 Given a / b = 2.0, b / c = 3.0.
 queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 return [6.0, 0.5, -1.0, 1.0, -1.0 ].
 
 The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.
 
 According to the example above:
 
 equations = [ ["a", "b"], ["b", "c"] ],
 values = [2.0, 3.0],
 queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
 The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
 
 */


/**
 
 构图 + 最短路
 
 11 / 11 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        unordered_map<string, unsigned> seq;
        unsigned increment = 0;
        
        for(pair<string, string> q : equations){
            if(seq.find(q.first) == seq.end()){
                seq[q.first] = increment++;
            }
            if(seq.find(q.second) == seq.end()){
                seq[q.second] = increment++;
            }
        }
        vector<vector<unsigned>> edges(increment, vector<unsigned>(0));
        vector<vector<double>> graph(increment, vector<double>(increment, -1.0));
        for(auto i=0; i<equations.size(); ++i){
            pair<string, string> q = equations[i];
            double val = values[i];
            edges[seq[q.first]].push_back(seq[q.second]);
            edges[seq[q.second]].push_back(seq[q.first]);
            graph[seq[q.first]][seq[q.second]] = val;
            graph[seq[q.second]][seq[q.first]] = 1.0 / val;
        }
        
        for(auto k = 0; k<queries.size(); ++k){
            pair<string, string> query = queries[k];
            if(seq.find(query.first) == seq.end() || seq.find(query.second) == seq.end()){
                ans.push_back(-1.0);
            } else if(query.first == query.second){
                ans.push_back(1.0);
            } else{
                typedef pair<unsigned, double> kk;
                queue<kk> q;
                vector<bool> visit(increment, false);
                q.push(make_pair(seq[query.first], 1.0));
                while(!q.empty()){
                    kk now = q.front();
                    q.pop();
                    visit[now.first] = true;
                    if(now.first == seq[query.second]){
                        ans.push_back(now.second);
                        break;
                    }
                    
                    for(unsigned next : edges[now.first]){
                        if(!visit[next]){
                            q.push(make_pair(next, now.second * graph[now.first][next]));
                        }
                    }
                    
                }
                
                if(ans.size() == k){
                    ans.push_back(-1.0);
                }
            }
        }
        
        
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    
    vector<pair<string, string>> equations = {make_pair("a", "b"),make_pair("b", "c")};
    vector<double> values = {2.0, 3.0};
    vector<pair<string, string>> queries = {make_pair("a", "c"),make_pair("b", "a"),make_pair("a", "e"),make_pair("a", "a"),make_pair("x", "x")};
    
    vector<double> ans = solve.calcEquation(equations, values, queries);
    for(double d : ans) cout<< d << endl;
    
    return 0;
}

