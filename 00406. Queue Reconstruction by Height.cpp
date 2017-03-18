//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 406. Queue Reconstruction by Height
 
 Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 
 Note:
 The number of people is less than 1,100.
 
 Example
 
 Input:
 [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 
 Output:
 [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 
 
 */


/**
 
 Greedy
 
 step 1. 排序，排序规则为 先按照k比较，若k相同则比较h
 step 2. 顺序取h，查看对应的low_bound，该同学的index为 low_bound + k
 
 37 / 37 test cases passed.
 Status: Accepted
 Runtime: 49 ms
 
 */



class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans(people.size(),make_pair(-1, -1));
        vector<int> tmp(0);
        sort(people.begin(), people.end(), [&](const pair<int, int> a,const pair<int, int> b){
            if(a.second == b.second) return a.first < b.first;
            
            return a.second < b.second;
        });
        
        vector<int>::iterator iter;
        for(unsigned long i = 0; i < people.size();i++){
            iter = lower_bound(tmp.begin(), tmp.end(), people[i].first, [&](const int a,const int b){
                return a < b;
            });
            
            unsigned long idx = iter - tmp.begin() + people[i].second;
            if(ans[idx].second == -1) ans[idx] = people[i];
            else ans.insert(ans.begin() + idx, people[i]);
            tmp.insert(iter, people[i].first);
        }
        
        while(ans.size() > people.size()) ans.pop_back();
        
        return ans;
    }
    
    void output(vector<pair<int, int>>& people){
        for_each(people.begin(), people.end(), [](const pair<int, int> people){
            cout<<people.first<<","<<people.second<<endl;
        });
    }
};


int main(){
    Solution solve;
    
    vector<pair<int, int>> people;
    // [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    people.push_back(make_pair(7, 0));
    people.push_back(make_pair(4, 4));
    people.push_back(make_pair(7, 1));
    people.push_back(make_pair(5, 0));
    people.push_back(make_pair(6, 1));
    people.push_back(make_pair(5, 2));
    
    vector<pair<int, int>> ans = solve.reconstructQueue(people);
    solve.output(ans);
    return 0;
}
