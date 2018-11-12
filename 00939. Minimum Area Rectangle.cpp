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
 Runtime: 168 ms
 
 */




// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        bool flag = false;
        
        sort(points.begin(), points.end(), [&](const vector<int> a, const vector<int> b){
            return a[0] < b[0];
        });
        
        unordered_map<int, vector<int> *> yx;
        for(vector<int> point : points){
            int x = point[0], y = point[1];
            if(!yx[y]){
                yx[y] = new vector<int>();
            }
            yx[y]->push_back(x);
        }
        
        
        
        for_each(yx.begin(), yx.end(), [&](const auto pi){
            if(pi.second->size() < 2){
                return ;
            }
            for_each(yx.begin(), yx.end(), [&](const auto pj){
                if(pi.first == pj.first  ||
                   pj.second->size() < 2){
                    return ;
                }
                vector<int> v = *(pj.second);
                for(auto i = 0; i<v.size(); ++i){
                    for(auto j = i+1; j<v.size(); ++j){
                        if(binary_search(pi.second->begin(), pi.second->end(), v[i]) &&
                           binary_search(pi.second->begin(), pi.second->end(), v[j])){
                            ans = min(ans, abs(pi.first - pj.first) * (v[j] - v[i]));
                            flag = true;
                        }
                    }
                }
            });
        });
        
        return flag ? ans : 0;
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

