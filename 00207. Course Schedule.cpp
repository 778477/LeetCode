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
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;

/**
 
 207. Course Schedule
 
 There are a total of n courses you have to take, labeled from 0 to n-1.
 
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 
 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 
 Example 1:
 
 Input: 2, [[1,0]]
 Output: true
 Explanation: There are a total of 2 courses to take.
 To take course 1 you should have finished course 0. So it is possible.
 Example 2:
 
 Input: 2, [[1,0],[0,1]]
 Output: false
 Explanation: There are a total of 2 courses to take.
 To take course 1 you should have finished course 0, and to take course 0 you should
 also have finished course 1. So it is impossible.
 Note:
 
 The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 You may assume that there are no duplicate edges in the input prerequisites.
 
 
 */


/**
 
 42 / 42 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */

static auto _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int finishCourses = 0;
        unordered_map<int, vector<int>> outDegree;
        vector<int> inDegree(numCourses, 0);
        //[0,1]  0 <- 1
        for(pair<int, int> d : prerequisites){
            outDegree[d.second].push_back(d.first);
            ++inDegree[d.first];
        }
        
        queue<int> doneCourese;
        
        for(int i=0;i<numCourses;++i){
            if(inDegree[i] == 0){
                doneCourese.push(i);
            }
        }
        
        while(!doneCourese.empty()){
            int c = doneCourese.front();
            doneCourese.pop();
            ++finishCourses;
            for(int cc : outDegree[c]){
                inDegree[cc]--;
                if(inDegree[cc] == 0){
                    doneCourese.push(cc);
                }
            }
        }
        
        
        
        return finishCourses == numCourses;
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    
    return 0;
}
