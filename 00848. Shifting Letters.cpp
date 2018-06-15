//
//  main.cpp
//  whiteBorad-leetcode
//
//  Created by 郭妙友 on 2018/3/30.
//  Copyright © 2018年 郭妙友. All rights reserved.
//

#include <iostream>

#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>


#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 848. Shifting Letters
 
 We have a string S of lowercase letters, and an integer array shifts.
 
 Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
 
 For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
 
 Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.
 
 Return the final string after all such shifts to S are applied.
 
 Example 1:
 
 Input: S = "abc", shifts = [3,5,9]
 Output: "rpl"
 Explanation:
 We start with "abc".
 After shifting the first 1 letters of S by 3, we have "dbc".
 After shifting the first 2 letters of S by 5, we have "igc".
 After shifting the first 3 letters of S by 9, we have "rpl", the answer.
 Note:
 
 1 <= S.length = shifts.length <= 20000
 0 <= shifts[i] <= 10 ^ 9
 
 */



/**
 
 46 / 46 test cases passed.
 Status: Accepted
 Runtime: 55 ms
 
 
 注意数据范围是会爆int的，使用accumulate传入的init value也需要指定int64_t
 
 */
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        string ans("");
        
        int64_t sum = accumulate(shifts.begin(), shifts.end(), (int64_t)0);
        int64_t curTotalSum = 0,tmp;
        
        for(size_t i = 0; i<S.length(); ++i){
            tmp = shifts[i];
            ans += (((S[i] - 'a' + sum - curTotalSum) % 26) + 'a');
            curTotalSum += tmp;
        }
        
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solve;
    
    vector<int> shifts{505870226,437526072,266740649,224336793,532917782,311122363,\
        567754492,595798950,81520022,684110326,137742843,275267355,\
        856903962,148291585,919054234,467541837,622939912,116899933,\
        983296461,536563513};
    string S("mkgfzkkuxownxvfvxasy");
    
    cout<<solve.shiftingLetters(S, shifts)<<endl;
    
    return 0;
}



/**
 Test Case #1.
 
 intput:
 "mkgfzkkuxownxvfvxasy"
 
 [505870226,437526072,266740649,224336793,532917782,311122363,\
 567754492,595798950,81520022,684110326,137742843,275267355,\
 856903962,148291585,919054234,467541837,622939912,116899933,\
 983296461,536563513]
 
 Expected:
 "wqqwlcjnkphhsyvrkdod"
 */

