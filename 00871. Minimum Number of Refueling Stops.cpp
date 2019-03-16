//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_set>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;


/*********************************
 
 871. Minimum Number of Refueling Stops
 
 A car travels from a starting position to a destination which is target miles east of the starting position.
 
 Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.
 
 The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.
 
 When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
 
 What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return -1.
 
 Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
 
 
 
 Example 1:
 
 Input: target = 1, startFuel = 1, stations = []
 Output: 0
 Explanation: We can reach the target without refueling.
 Example 2:
 
 Input: target = 100, startFuel = 1, stations = [[10,100]]
 Output: -1
 Explanation: We can't reach the target (or even the first gas station).
 Example 3:
 
 Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
 Output: 2
 Explanation:
 We start with 10 liters of fuel.
 We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
 Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
 and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
 We made 2 refueling stops along the way, so we return 2.
 
 
 Note:
 
 1 <= target, startFuel, stations[i][1] <= 10^9
 0 <= stations.length <= 500
 0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target
 
 
 *********************************/

/**
 198 / 198 test cases passed.
 Status: Accepted
 Runtime: 24 ms
 Memory Usage: 14.2 MB
 
 贪心 + 优先队列(大根堆)
 
 */

// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        
        if(startFuel >= target) return 0;
        
        priority_queue<int, vector<int>, less<int>> heap;
        
        
        for(auto i=0;i<stations.size(); ++i){
            auto it = stations[i];
            if(startFuel < it[0]) break;
            heap.push(it[1]);
        }
        
        
        while (!heap.empty()) {
            auto cur = heap.top();
            heap.pop();
            
            startFuel += cur;
            ++ans;
            if(startFuel >= target) return ans;
            
            for(auto i = heap.size() + ans ; i<stations.size(); ++i){
                auto it = stations[i];
                if(startFuel < it[0]) break;
                
                heap.push(it[1]);
            }
        }
        
        
        return -1;
    }
};


/*
 1000
 299
 [[14,123],[145,203],[344,26],[357,68],[390,35],[478,135],[685,108],[823,186],[934,217],[959,80]]
 */
int main(){
    
    
    Solution solution;
    vector<vector<int>> stations;
    stations.push_back({14,123});  // 299+123 = 422
    stations.push_back({145,203}); // 299+203 = 502
    stations.push_back({344,26});  //
    stations.push_back({357,68});
    stations.push_back({390,35});
    stations.push_back({478,135}); // 299+135+478
    stations.push_back({685,108});
    stations.push_back({823,186});
    stations.push_back({934,217});
    stations.push_back({959,80});
    cout<<solution.minRefuelStops(1000, 299, stations)<<endl;
    
    
    return 0;
}

