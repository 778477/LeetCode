//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy on 16/9/26.
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;


/*
 
 210. Course Schedule II
 Total Accepted: 41448
 Total Submissions: 171041
 Difficulty: Medium
 Contributors: Admin
 There are a total of n courses you have to take, labeled from 0 to n - 1.
 
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 
 Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 
 There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 
 For example:
 
 2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 
 4, [[1,0],[2,0],[3,1],[3,2]]
 There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 
 Note:
 The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 
 */

/*
 Course Schedule II	Accepted	102 ms	cpp
 */
const int kArrayQueueLimitSize = 2048;
vector<vector<int>> maze(kArrayQueueLimitSize,vector<int>(kArrayQueueLimitSize,0));
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int *inDegree = (int *)malloc(sizeof(int) * numCourses);
        int *arrQueue = (int *)malloc(sizeof(int) * numCourses);
        vector<int> ans;
        
        memset(inDegree, 0, sizeof(int) * numCourses);
        memset(arrQueue, 0, sizeof(int) * numCourses);
        maze.assign(numCourses, vector<int>(numCourses,0));
        
        
        for_each(prerequisites.begin(), prerequisites.end(), [&](const pair<int, int> p){
            if(!maze[p.second][p.first]){
                maze[p.second][p.first] = 1;
                inDegree[p.first]++;
            }
        });
        
        int arrQueueStarIdx = 0, arrQueueEndIdx = 0;
        for(int i=0;i<numCourses;i++){
            if(!inDegree[i]){
                arrQueue[arrQueueEndIdx] = i;
                arrQueueEndIdx = (arrQueueEndIdx + 1)%kArrayQueueLimitSize;
            }
        }
        
        int outNodeCount = 0;
        while(arrQueueStarIdx != arrQueueEndIdx){
            int idx = arrQueue[arrQueueStarIdx];
            ans.push_back(idx);
            arrQueueStarIdx = (arrQueueStarIdx + 1)%kArrayQueueLimitSize;
            outNodeCount++;
            
            for(int i=0;i<numCourses;i++){
                if(maze[idx][i]){
                    inDegree[i]--;
                    if(!inDegree[i]){
                        arrQueue[arrQueueEndIdx] = i;
                        arrQueueEndIdx = (arrQueueEndIdx + 1)%kArrayQueueLimitSize;
                    }
                }
            }
        }
        
        
        free(inDegree),free(arrQueue);
        
        if(outNodeCount != numCourses) return vector<int>(0);
        
        return ans;
    }
};


int main(){
    Solution *solve = new Solution();
    vector<pair<int, int>> p;
    p.push_back(make_pair(5,8));
    p.push_back(make_pair(3,5));
    p.push_back(make_pair(1,9));
    p.push_back(make_pair(4,5));
    p.push_back(make_pair(0,2));
    p.push_back(make_pair(1,9));
    p.push_back(make_pair(7,8));
    p.push_back(make_pair(4,9));
    
    
    vector<int> ans = solve->findOrder(8, p);
    for_each(ans.begin(), ans.end(), [](const int task){
        cout<<task<<endl;
    });
    
    return 0;
}
