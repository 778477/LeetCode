//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 423. Reconstruct Original Digits from English
 
 Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
 
 Note:
 Input contains only lowercase English letters.
 Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
 Input length is less than 50,000.
 Example 1:
 Input: "owoztneoer"
 
 Output: "012"
 Example 2:
 Input: "fviefuro"
 
 Output: "45"
 
 
 */


/**
 
 Math
 
 24 / 24 test cases passed.
 Status: Accepted
 Runtime: 26 ms
 
 */



class Solution {
public:
    string originalDigits(string s) {
        stringstream stream;
        vector<unsigned> litterCount(26,0);
        vector<unsigned> numberCount(10,0);
        
        for(char ch : s) ++litterCount[ ch - 'a' ];
        
        // 0: zero -> z
        numberCount[0] = litterCount['z' - 'a'];
        litterCount['e' - 'a'] -= numberCount[0];
        litterCount['r' - 'a'] -= numberCount[0];
        litterCount['o' - 'a'] -= numberCount[0];
        // 2: two -> w
        numberCount[2] = litterCount['w' - 'a'];
        litterCount['t' - 'a'] -= numberCount[2];
        litterCount['o' - 'a'] -= numberCount[2];
        // 4: four -> u
        numberCount[4] = litterCount['u' - 'a'];
        litterCount['f' - 'a'] -= numberCount[4];
        litterCount['o' - 'a'] -= numberCount[4];
        litterCount['r' - 'a'] -= numberCount[4];
        // 5: five -> f
        numberCount[5] = litterCount['f' - 'a'];
        litterCount['i' - 'a'] -= numberCount[5];
        litterCount['v' - 'a'] -= numberCount[5];
        litterCount['e' - 'a'] -= numberCount[5];
        // 1: one -> o
        numberCount[1] = litterCount['o' - 'a'];
        litterCount['n' - 'a'] -= numberCount[1];
        litterCount['e' - 'a'] -= numberCount[1];
        // 3: three -> r
        numberCount[3] = litterCount['r' - 'a'];
        litterCount['t' - 'a'] -= numberCount[3];
        litterCount['h' - 'a'] -= numberCount[3];
        litterCount['e' - 'a'] -= (2 * numberCount[3]);
        // 6: six -> x
        numberCount[6] = litterCount['x' - 'a'];
        litterCount['s' - 'a'] -= numberCount[6];
        litterCount['i' - 'a'] -= numberCount[6];
        // 7: seven -> s
        numberCount[7] = litterCount['s' - 'a'];
        litterCount['e' - 'a'] -= (2 * numberCount[7]);
        litterCount['v' - 'a'] -= numberCount[7];
        litterCount['n' - 'a'] -= numberCount[7];
        // 8: eight -> g
        numberCount[8] = litterCount['g' - 'a'];
        litterCount['e' - 'a'] -= numberCount[8];
        litterCount['i' - 'a'] -= numberCount[8];
        litterCount['h' - 'a'] -= numberCount[8];
        litterCount['t' - 'a'] -= numberCount[8];
        // 9: nine -> i
        numberCount[9] = litterCount['i' - 'a'];
        litterCount['n' - 'a'] -= (2 * numberCount[9]);
        litterCount['e' - 'a'] -= numberCount[9];
        
        
        for(unsigned i = 0; i<10;i++)
            for(unsigned j = 0;j<numberCount[i];j++) stream<<i;
        
        
        return stream.str();
    }
};

int main(){
    Solution solve;
    
    cout<<solve.originalDigits("fviefuro")<<endl;
    
    return 0;
}
