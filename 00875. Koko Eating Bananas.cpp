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
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 875. Koko Eating Bananas
 
 Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.
 
 Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.
 
 Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
 
 Return the minimum integer K such that she can eat all the bananas within H hours.
 
 
 
 Example 1:
 
 Input: piles = [3,6,7,11], H = 8
 Output: 4
 Example 2:
 
 Input: piles = [30,11,23,4,20], H = 5
 Output: 30
 Example 3:
 
 Input: piles = [30,11,23,4,20], H = 6
 Output: 23
 
 
 Note:
 
 1 <= piles.length <= 10^4
 piles.length <= H <= 10^9
 1 <= piles[i] <= 10^9
 
 */

/**
 
 
 113 / 113 test cases passed.
 Status: Accepted
 Runtime: 20 ms
 
 1. 注意不要 accumulate 不要溢出
 2. 尽量不要使用取余运算
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int ans = 0;
        long long sum = 0;
        
        int left =  1;
        int right = *max_element(piles.begin(), piles.end());
        
        ans = right;
        if(piles.size() == H){
            return ans;
        }
        
        sum = accumulate(piles.begin(), piles.end(), sum);
        if(H >= sum){
            return 1;
        }
        
        int tmpTime = 0,mid;
        while(left <= right){
            mid = ((right - left)>>1) + left;
            tmpTime = 0;
            for(int pile : piles){
                tmpTime = tmpTime + ( (pile + mid - 1)/mid);
            }
            if(tmpTime > H){
                left = mid + 1;
            } else if(tmpTime <= H){
                ans = min(ans, mid);
                right = mid - 1;
            }
            
        }
        
        return ans;
    }
};


/**
 Test Case 1:
 [332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184]
 823855818
 
 */

int main(){
    
    Solution solve;
    vector<int> A = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    cout<<solve.minEatingSpeed(A, 823855818)<<endl;
    
    return 0;
}
