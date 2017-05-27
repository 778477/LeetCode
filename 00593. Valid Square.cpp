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
 
 593. Valid Square
 
 Given the coordinates of four points in 2D space, return whether the four points could construct a square.
 
 The coordinate (x,y) of a point is represented by an integer array with two integers.
 
 Example:
 Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 Output: True
 Note:
 
 All the input integers are in the range [-10000, 10000].
 A valid square has four equal sides with positive length and four equal angles (90-degree angles).
 Input points have no order.
 
 
 */

/*
 
 两直线垂直相交，斜率之积为-1. 注意斜率不存在的情况，注意double精度问题
 
 244 / 244 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */


typedef pair<int, int> _Point;
class Solution {
public:
    bool perpendicular(_Point a, _Point b, _Point c){
        
        if(a.first == b.first){
            return b.second == c.second;
        } else if(b.first == c.first){
            return a.second == b.second;
        } else {
            double k1 = (a.second - b.second)*1.0 / (a.first - b.first);
            double k2 = (b.second - c.second)*1.0 / (b.first - c.first);
            
            return k1*k2 + 1 < 1e-6;
        }
        
        return false;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        _Point a,b,c,d;
        a.first = p1.front(), a.second = p1.back();
        b.first = p2.front(), b.second = p2.back();
        c.first = p3.front(), c.second = p3.back();
        d.first = p4.front(), d.second = p4.back();
        
        vector<_Point> ps;
        ps.push_back(a),ps.push_back(b),ps.push_back(c),ps.push_back(d);
        
        sort(ps.begin(), ps.end(), [&](const _Point& p1, const _Point& p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            
            return p1.first < p2.first;
        });
        
        double edge = hypot(ps[0].first - ps[1].first, ps[0].second - ps[1].second);
        if(edge - 0 < 1e-6) return false;
        if(edge != hypot(ps[0].first - ps[2].first, ps[0].second - ps[2].second)) return false;
        if(edge != hypot(ps[1].first - ps[3].first, ps[1].second - ps[3].second)) return false;
        if(edge != hypot(ps[2].first - ps[3].first, ps[2].second - ps[3].second)) return false;
        
        if(!perpendicular(ps[0], ps[1], ps[3])) return false;
        if(!perpendicular(ps[1], ps[3], ps[2])) return false;
        
        return true;
    }
};

/**
 test case:
 [-658,-2922]
 [-965,-4209]
 [-2252,-3902]
 [-1945,-2615]
 
 
 */


int main(){
    Solution solve;
    
    vector<int> p1{-658,-2922};
    vector<int> p2{-965,-4209};
    vector<int> p3{-2252,-3902};
    vector<int> p4{-1945,-2615};
    
    cout<<solve.validSquare(p1, p2, p3, p4)<<endl;
    
    return 0;
}
