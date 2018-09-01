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



/**
 
 710. Random Pick with Blacklist
 
 Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.
 
 Optimize it such that it minimizes the call to system’s Math.random().
 
 Note:
 
 1 <= N <= 1000000000
 0 <= B.length < min(100000, N)
 [0, N) does NOT include N. See interval notation.
 Example 1:
 
 Input:
 ["Solution","pick","pick","pick"]
 [[1,[]],[],[],[]]
 Output: [null,0,0,0]
 Example 2:
 
 Input:
 ["Solution","pick","pick","pick"]
 [[2,[]],[],[],[]]
 Output: [null,1,1,1]
 Example 3:
 
 Input:
 ["Solution","pick","pick","pick"]
 [[3,[1]],[],[],[]]
 Output: [null,0,0,2]
 Example 4:
 
 Input:
 ["Solution","pick","pick","pick"]
 [[4,[2]],[],[],[]]
 Output: [null,1,3,1]
 Explanation of Input Syntax:
 
 The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any. */

/**
 
 67 / 67 test cases passed.
 Status: Accepted
 Runtime: 120 ms
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();

class Solution {
public:
    
    vector<int> whitelist;
    int n;
    unordered_set<int> set;
    Solution(int N, vector<int> blacklist) {
        n = N;
        set = unordered_set<int>(blacklist.begin(), blacklist.end());
        
        if (blacklist.size() > n/2) {
            for(auto i=0;i<n;++i){
                if(!set.count(i)) whitelist.push_back(i);
            }
        }
    }
    
    int pick() {
        if(!whitelist.empty()){
            return whitelist[rand() % whitelist.size()];
        }
        
        int ans;
        do {
            ans = rand() % n;
        } while (set.count(ans));
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */


int main(){
    
    
    return 0;
}


