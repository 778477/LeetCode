//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 849. Maximize Distance to Closest Person
 
 In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.
 
 There is at least one empty seat, and at least one person sitting.
 
 Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
 
 Return that maximum distance to closest person.
 
 Example 1:
 
 Input: [1,0,0,0,1,0,1]
 Output: 2
 Explanation:
 If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
 If Alex sits in any other open seat, the closest person has distance 1.
 Thus, the maximum distance to the closest person is 2.
 Example 2:
 
 Input: [1,0,0,0]
 Output: 3
 Explanation:
 If Alex sits in the last seat, the closest person is 3 seats away.
 This is the maximum distance possible, so the answer is 3.
 Note:
 
 1 <= seats.length <= 20000
 seats contains only 0s or 1s, at least one 0, and at least one 1.
 
 */

/**
 
 79 / 79 test cases passed.
 Status: Accepted
 Runtime: 15 ms
 
 注意头尾的情况
 
 */

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int begin = 0,ans = 0,step = 0;
        size_t idx = 0;
        
        while(seats[idx] == 0){
            ++idx;
            ++step;
        }
        
        begin = step;
        
        step = 0;
        for(size_t i=idx; i<seats.size(); ++i){
            if(seats[i] == 1){
                ans = max(ans, step + 1);
                step = 0;
            } else {
                ++step;
            }
        }
        
        
        
        return max(ans/2,max(begin,step));
    }
};

int main(){
    Solution solve;
    
    vector<int> seats = {0,0,1};
    cout<<solve.maxDistToClosest(seats)<<endl;
    
    return 0;
}
