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
 
 https://leetcode.com/problems/minimum-area-rectangle/
 
 939. Minimum Area Rectangle
 
 Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.
 
 If there isn't any rectangle, return 0.
 
 
 
 Example 1:
 
 Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
 Output: 4
 Example 2:
 
 Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 Output: 2
 
 
 Note:
 
 1 <= points.length <= 500
 0 <= points[i][0] <= 40000
 0 <= points[i][1] <= 40000
 All points are distinct.


 */

/**
 

 137 / 137 test cases passed.
 Status: Accepted
 Runtime: 60 ms
 
 更新了一下实现：看到评论区发现原来C++自带了 交集实现set_intersection。
 
 去掉了原来n^2的遍历的逻辑，代码变得更加优雅一些。
 
 有些解法利用set做点集。这里我的实现是 先hash，做边集。
 
 */




// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points, int ans = INT_MAX) {

       
        unordered_map<int, set<int>> yx;
        for(vector<int> point : points){
            yx[point[0]].insert(point[1]);
        }
        
        
        for(auto pi = yx.begin(); pi != yx.end(); ++pi){
            if(pi->second.size() < 2) continue;
            for(auto pj = next(pi); pj != yx.end(); ++pj){
                if(pj->second.size() < 2) continue;
                vector<int> y;
                vector<int> u;
                
                set_intersection(begin(pi->second), end(pi->second),
                                 begin(pj->second), end(pj->second),
                                 inserter(y, y.begin()));
                
                for(auto k = 1; k<y.size(); ++k){
                    ans = min(ans, abs(pj->first - pi->first) * (y[k] - y[k-1]));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


/**
 [[0,1],[1,3],[3,3],[4,4],[1,4],[2,3],[1,0],[3,4]]
 
 */

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    
    vector<vector<int>> points = {{0,1},{1,3},{3,3},{4,4},{1,4},{2,3},{1,0},{3,4}};
    cout<<solve.minAreaRect(points)<<endl;
    
    return 0;
}
