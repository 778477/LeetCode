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
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 869. Reordered Power of 2
 
 Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.
 
 Return true if and only if we can do this in a way such that the resulting number is a power of 2.
 
 
 
 Example 1:
 
 Input: 1
 Output: true
 Example 2:
 
 Input: 10
 Output: false
 Example 3:
 
 Input: 16
 Output: true
 Example 4:
 
 Input: 24
 Output: false
 Example 5:
 
 Input: 46
 Output: true
 
 
 Note:
 
 1 <= N <= 10^9
 
 */

/**
 
 135 / 135 test cases passed.
 Status: Accepted
 Runtime: 100 ms
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        
        string str = to_string(N);
        sort(str.begin(), str.end());
        int tmp,count;
        do {
            count = 0;
            tmp = (int)strtol(str.c_str(),NULL, 10);
            if(tmp < pow(10, str.size() - 1)){
                continue;
            }
            while(tmp && count < 2){
                count = count + ((tmp&0x01)?1:0);
                tmp>>=1;
            }
            if(count == 1){
                return true;
            }
            
        } while (next_permutation(str.begin(), str.end()));
        
        
        return false;
    }
};

int main(){
    
    
    Solution solve;
    cout<<solve.reorderedPowerOf2(218)<<endl;
    
    return 0;
}
