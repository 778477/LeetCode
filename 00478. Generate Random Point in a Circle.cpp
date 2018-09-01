//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

/**
 
 478. Generate Random Point in a Circle
 
 Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.
 
 Note:
 
 input and output values are in floating-point.
 radius and x-y position of the center of the circle is passed into the class constructor.
 a point on the circumference of the circle is considered to be in the circle.
 randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.
 Example 1:
 
 Input:
 ["Solution","randPoint","randPoint","randPoint"]
 [[1,0,0],[],[],[]]
 Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
 Example 2:
 
 Input:
 ["Solution","randPoint","randPoint","randPoint"]
 [[10,5,-7.5],[],[],[]]
 Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
 Explanation of Input Syntax:
 
 The input is two lists: the subroutines called and their arguments. Solution's constructor has three arguments, the radius, x-position of the center, and y-position of the center of the circle. randPoint has no arguments. Arguments are always wrapped with a list, even if there aren't any.
 
 
 
 
 */


/**
 
 8 / 8 test cases passed.
 Status: Accepted
 Runtime: 172 ms
 
 */

static auto _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();

class Solution {
private:
    double r,cx,cy;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        cx = x_center;
        cy = y_center;
        
        srand((int)time(NULL));
    }
    
    bool reject_sampling(double x,double y){
        return sqrt((x-cx)*(x-cx)+(y-cy)*(y-cy)) > r;
    }
    
    vector<double> randPoint() {
        vector<double> point;
        double tmpx = 0, tmpy = 0;
        const int dir[4][2] = {{-1,1},{1,1},{-1,-1},{1,-1}};
        do {
            int i = rand()%4;
            tmpx = cx + dir[i][0]*(random()%(long)(r*100000))*1.0/100000;
            tmpy = cy + dir[i][1]*(random()%(long)(r*100000))*1.0/100000;
        } while (reject_sampling(tmpx, tmpy));
        
        point.push_back(tmpx);
        point.push_back(tmpy);
        return point;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    
    Solution solve(1,0,0);
    vector<double> point = solve.randPoint();
    cout<<point[0]<<","<<point[1]<<endl;
    
    
    return 0;
}
