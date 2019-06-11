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
 
 1014. Capacity To Ship Packages Within D Days
 
 A conveyor belt has packages that must be shipped from one port to another within D days.
 
 The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
 
 Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.
 
 
 
 Example 1:
 
 Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
 Output: 15
 Explanation:
 A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
 1st day: 1, 2, 3, 4, 5
 2nd day: 6, 7
 3rd day: 8
 4th day: 9
 5th day: 10
 
 Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
 Example 2:
 
 Input: weights = [3,2,2,4,1,4], D = 3
 Output: 6
 Explanation:
 A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
 1st day: 3, 2
 2nd day: 2, 4
 3rd day: 1, 4
 Example 3:
 
 Input: weights = [1,2,3,1,1], D = 4
 Output: 3
 Explanation:
 1st day: 1
 2nd day: 2
 3rd day: 3
 4th day: 1, 1
 
 
 Note:
 
 1 <= D <= weights.length <= 50000
 1 <= weights[i] <= 500
 
 *********************************/

/**
 将数组划分为D个子序列，使子序列之和最小。
 二分枚举子序列之和 sum，使数组划分为D个，其和小于等于sum
 
 82 / 82 test cases passed.
 Status: Accepted
 Runtime: 28 ms
 Memory Usage: 12.1 MB
 
 */

// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();


class Solution {
public:
    int shipWithinDays(vector<int>& w, int D) {
        
        int low = *max_element(w.begin(), w.end());
        int hight = accumulate(w.begin(), w.end(), 0);
        
        if(D == 1) return hight;
        if(D == w.size()) return low;
        
        while(low < hight){
            int mid = low + ((hight - low)>>1);
            int p = 0;
            int buf = 0;
            for(int i=0;i<w.size(); i++){
                if(buf + w[i] > mid){
                    p += 1;
                    buf = w[i];
                } else{
                    buf += w[i];
                }
                if(p > D) break;
            }
            p += 1;
            
            if(p > D){
                low = mid + 1;
            } else {
                hight = mid;
            }
        }
        
        return hight;
    }
};

int main(){
    
    
    Solution solution;
    
    vector<int> w(10,0);
    iota(w.begin(), w.end(), 1);
    cout<<solution.shipWithinDays(w, 5)<<endl;
    
    
    return 0;
}

