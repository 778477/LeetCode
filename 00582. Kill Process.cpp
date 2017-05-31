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
 
 
 582. Kill Process
 
 Given n processes, each process has a unique PID (process id) and its PPID (parent process id).
 
 Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.
 
 We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.
 
 Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.
 
 Example 1:
 Input:
 pid =  [1, 3, 10, 5]
 ppid = [3, 0, 5, 3]
 kill = 5
 Output: [5,10]
 Explanation:
 3
 /   \
 1     5
 /
 10
 
 Kill 5 will also kill 10.
 Note:
 The given kill id is guaranteed to be one of the given PIDs.
 n >= 1.
 
 
 */

/*
 
 预处理，合并相同父进程号
 
 166 / 166 test cases passed.
 Status: Accepted
 Runtime: 205 ms
 
 */



class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> p;
        queue<int> q;
        
        map<int,vector<int>> table;
        
        for(auto i = 0;i<ppid.size();i++){
            table[ppid[i]].push_back(pid[i]);
        }
        
        q.push(kill);
        while(!q.empty()){
            int k = q.front();
            q.pop();
            p.push_back(k);
            
            if(!table[k].empty()){
                for(int p : table[k]) q.push(p);
            }
        }
        
        return p;
    }
};

int main(){
    
    vector<int> pid{1,3,10,5};
    vector<int> ppid{3,0,5,3};
    
    Solution solve;
    
    vector<int> kp = solve.killProcess(pid, ppid, 3);
    
    for(int p : kp){
        cout<<p<<endl;
    }
    
    return 0;
}
