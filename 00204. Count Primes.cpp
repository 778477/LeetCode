//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 
 204. Count Primes
 
 Total Accepted: 98807
 Total Submissions: 377477
 Difficulty: Easy
 Contributors: Admin
 Description:
 
 Count the number of prime numbers less than a non-negative number, n.
 */


/**
 
 20 / 20 test cases passed.
 Status: Accepted
 Runtime: 103 ms
 
 */

class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        bool *vis = (bool *)malloc(sizeof(bool) * (n + 1));
        memset(vis, true, sizeof(bool) * (n+1));
        
        for(int i=2;i<n;i++){
            for(int j=2; j*i < n;j++){
                vis[j*i] = false;
            }
        }
        
        for(int i=2;i<n;i++){
            if(vis[i]) ans++;
        }
        
        free(vis);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    Solution solve;
    cout<<solve.countPrimes(5)<<endl;
    return 0;
}
