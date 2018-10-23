
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

#include <algorithm>
#include <functional>

using namespace std;



/**
 https://leetcode.com/problems/flip-string-to-monotone-increasing/
 
 A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)
 
 We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.
 
 Return the minimum number of flips to make S monotone increasing.
 
 
 
 Example 1:
 
 Input: "00110"
 Output: 1
 Explanation: We flip the last digit to get 00111.
 Example 2:
 
 Input: "010110"
 Output: 2
 Explanation: We flip to get 011111, or alternatively 000111.
 Example 3:
 
 Input: "00011000"
 Output: 2
 Explanation: We flip to get 00000000.
 
 
 Note:
 
 1 <= S.length <= 20000
 S only consists of '0' and '1' characters.
 
 */

/**
 
 81 / 81 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */



// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
    public:
    int minFlipsMonoIncr(string S) {
        int one = 0, zero = 0;
        int ans = 20000;
        for(char c : S){
            if(c == '0') ++one;
        }
        
        ans = min(ans, one);
        
        for(char c : S){
            if(c == '0') --one;
            else ++zero;
            
            ans = min(ans, zero + one);
        }
        
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    return 0;
}
