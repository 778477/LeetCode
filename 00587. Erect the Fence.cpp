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
 
 
 587. Erect the Fence
 
 There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.
 
 Example 1:
 Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
 Explanation:
 
 Example 2:
 Input: [[1,2],[2,2],[4,2]]
 Output: [[1,2],[2,2],[4,2]]
 Explanation:
 
 Even you only have trees in a line, you need to use rope to enclose them.
 Note:
 
 All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
 All input integers will range from 0 to 100.
 The garden has at least one tree.
 All coordinates are distinct.
 Input points have NO order. No order required for output.
 Subscribe to see which companies asked this question.
 
 
 */

/*
 
 Graham Scan 凸包算法
 
 82 / 82 test cases passed.
 Status: Accepted
 Runtime: 26 ms
 
 */





struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
    int across(const Point a,const Point b,const Point c){
        return (a.x - c.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x);
    }
    
    bool ensureLine(vector<Point>& points){
        for(auto i=2;i<points.size();i++){
            if(across(points[i-2], points[i-1], points[i]) != 0) return false;
        }
        return true;
    }
    
    vector<Point> outerTrees(vector<Point>& points) {
        
        sort(points.begin(),points.end(),[&](const Point a,const Point b){
            return a.x != b.x ? a.x < b.x : a.y < b.y;
        });
        
        if(ensureLine(points)) return points;
        
        vector<Point> ans;
        for (auto i = 0; i < points.size(); i++){
            while(ans.size() > 1 && across(ans[ans.size() - 2], ans[ans.size() - 1], points[i]) < 0){
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }
        
        unsigned long tmp = ans.size();
        for(int i = (int)points.size() - 2; i>-1; --i){
            while (ans.size() > tmp && across(ans[ans.size() - 2], ans[ans.size() - 1], points[i]) < 0) {
                ans.pop_back();
            }
            ans.push_back(points[i]);
        }
        ans.pop_back();
        return ans;
    }
};

/**
 
 Test Case 1:
 Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
 
 Test Case 2:
 Input: [[1,2],[2,2],[4,2]]
 Output: [[1,2],[2,2],[4,2]]
 
 */

int main(){
    
    
    vector<Point> tc1{Point(1, 1),Point(2,2),Point(2,0),Point(2,4),Point(3,3),Point(4, 2)};
    vector<Point> tc2{Point(1, 2),Point(2, 2),Point(4, 2)};
    Solution solve;
    
    vector<Point> ans = solve.outerTrees(tc2);
    
    cout<<"[";
    for(Point p : ans){
        cout<<"["<<p.x<<","<<p.y<<"]"<<",";
    }
    cout<<"]"<<endl;
    
    return 0;
}
