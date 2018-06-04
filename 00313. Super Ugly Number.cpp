//
//  main.cpp
//  whiteBorad-leetcode
//
//  Created by 郭妙友 on 2018/3/30.
//  Copyright © 2018年 郭妙友. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;


/**
 
 # nthUglyNumber
 596 / 596 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
 # nthSuperUglyNumber
 83 / 83 test cases passed.
 Status: Accepted
 Runtime: 44 ms
 
 */
class Solution {
    public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglyNums{1};
        vector<int> uglyFactorCount(primes.size(), 0);
        
        while(uglyNums.size() < n){
            int tmpVal = INT_MAX;
            
            for(auto i = 0; i<primes.size(); ++i){
                tmpVal = min(tmpVal, primes[i] * uglyNums[uglyFactorCount[i]]);
            }
            
            
            for(auto i = 0; i<primes.size(); ++i){
                if(tmpVal == primes[i] * uglyNums[uglyFactorCount[i]]){
                    uglyFactorCount[i]++;
                }
            }
            
            uglyNums.push_back(tmpVal);
            
        }
        return uglyNums[n - 1];
    }
    int nthUglyNumber(int n) {
        vector<int> primes{2,3,5};
        return nthSuperUglyNumber(n, primes);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solve;
    cout<<solve.nthUglyNumber(10)<<endl;
    
    vector<int> prims{2,7,13,19};
    cout<<solve.nthSuperUglyNumber(12, prims)<<endl;
    
    return 0;
}

