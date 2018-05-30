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
using namespace std;

/**
 
 621. Task Scheduler
 
 Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 
 However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 
 You need to return the least number of intervals the CPU will take to finish all the given tasks.
 
 Example 1:
 Input: tasks = ["A","A","A","B","B","B"], n = 2
 Output: 8
 Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 Note:
 The number of tasks is in the range [1, 10000].
 The integer n is in the range [0, 100].
 
 
 
 */



/**
 
 64 / 64 test cases passed.
 Status: Accepted
 Runtime: 75 ms
 
 */

class Solution {
    public:
    typedef pair<char, unsigned> task;
    
    template<typename T> void forEachTask(T& queue,unsigned size){
        vector<task> tmp;
        
        for(unsigned i = 0; i<size; ++i){
            task t = queue.top();
            queue.pop();
            
            t.second--;
            if(t.second > 0){
                tmp.push_back(t);
            }
        }
        
        for(auto i = 0; i<tmp.size(); ++i){
            queue.push(tmp[i]);
        }
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<unsigned> tCount(26,0);
        for(char t : tasks){
            ++tCount[t-'A'];
        }
        
        auto cmp = [](task t1,task t2){
            return t1.second < t2.second;
        };
        priority_queue<task, vector<task>,decltype(cmp)> q(cmp);
        for(int i=0;i<26;i++){
            if(tCount[i] > 0){
                q.push(make_pair(i+'A', tCount[i]));
            }
        }
        
        int times = 0;
        unsigned taskCount = (unsigned)tasks.size();
        
        while(!q.empty()){
            if(q.size() > n){
                forEachTask(q, n+1);
                times += (n+1);
                taskCount -= (n+1);
                
            } else {
                taskCount -= q.size();
                
                if(taskCount == 0){
                    times += q.size();
                    break;
                }
                
                forEachTask(q, (unsigned)q.size());
                times += (n+1);
            }
        }
        return times;
    }
};



int main(int argc, const char * argv[]) {
    
    Solution solve;
    
    vector<char> tasks({'A','A','A','A','A','A','B','C','D','E','F','G'});
    
    cout<<solve.leastInterval(tasks, 6)<<endl;
    
    return 0;
}
