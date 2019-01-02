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
 
 963. Minimum Area Rectangle II
 DescriptionHintsSubmissionsDiscussSolution
 Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the x and y axes.
 
 If there isn't any rectangle, return 0.
 
 
 
 Example 1:
 
 
 
 Input: [[1,2],[2,1],[1,0],[0,1]]
 Output: 2.00000
 Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
 Example 2:
 
 
 
 Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
 Output: 1.00000
 Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
 Example 3:
 
 
 
 Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
 Output: 0
 Explanation: There is no possible rectangle to form from these points.
 Example 4:
 
 
 
 Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
 Output: 2.00000
 Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.
 
 
 Note:
 
 1 <= points.length <= 50
 0 <= points[i][0] <= 40000
 0 <= points[i][1] <= 40000
 All points are distinct.
 Answers within 10^-5 of the actual value will be accepted as correct.
 
 */


/**
 
 思路：
 1. 数据小，可以考虑暴力枚举 矩形
 2. 判断四个点形成的四边形是矩形
 2.1 计算 中点(cx,cy) 4个顶点到中点的距离相等即为矩形
 3. 计算四个点形成的四边形面积
 
 
 109 / 109 test cases passed.
 Status: Accepted
 Runtime: 92 ms
 
 */

class Solution {
public:
    typedef pair<int, int> point;
    const double ACC = 1e-5;
    
    double side(const point a, double x, double y){
        return (a.first - x) * (a.first - x) + (a.second - y) * (a.second - y);
    }
    
    int side(const point a, const point b){
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }
    
    double reacangleArea(const point a, const point b, const point c, const point d){
        return sqrt(side(a, b)) * sqrt(side(a, c));
    }
    
    bool isRectangle(const point a, const point b, const point c, const point d){
        double cx = (a.first + b.first + c.first + d.first) * 1.0 / 4;
        double cy = (a.second + b.second + c.second + d.second) * 1.0 / 4;
        
        double d1 = side(a, cx, cy);
        double d2 = side(b, cx, cy);
        double d3 = side(c, cx, cy);
        double d4 = side(d, cx, cy);
        
        return fabs(d1 - d2) < ACC && fabs(d2 - d3) < ACC && fabs(d3 - d4) < ACC;
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        double ans = INT_MAX;
        
        
        vector<point> ps;
        for(vector<int> p : points){
            ps.push_back(make_pair(p[0], p[1]));
        }
        sort(ps.begin(), ps.end(), [](const point a, const point b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        for(auto a=0;a<ps.size();++a)
            for(auto b=a+1;b<ps.size();++b)
                for(auto c=b+1;c<ps.size();++c)
                    for (auto d=c+1; d<ps.size(); ++d) {
                        if(isRectangle(ps[a], ps[b], ps[c], ps[d])){
                            double area = reacangleArea(ps[a], ps[b], ps[c], ps[d]);
                            if(ans - area > ACC){
                                ans = area;
                            }
                        }
                    }
        return ans == INT_MAX ? 0 : ans;
    }
};



int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<vector<int>> ps = {{3,0},{0,1},{1,0},{3,3},{2,3},{0,2},{2,1}};
    cout<<solve.minAreaFreeRect(ps)<<endl;
    return 0;
}

