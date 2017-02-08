//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

/**
 
 338. Counting Bits
 Description  Submission  Solutions  Add to List
 Total Accepted: 64207
 Total Submissions: 107677
 Difficulty: Medium
 Contributors: Admin
 Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 
 Example:
 For num = 5 you should return [0,1,1,2,1,2].
 
 Follow up:
 
 It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
 Space complexity should be O(n).
 Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 Show Hint
 
 
 */


/**
 
 15 / 15 test cases passed.
 Status: Accepted
 Runtime: 72 ms
 
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        
        for(int i=1;i<=num;i++){
            ans[i] = ans[i&(i-1)] + 1;
        }
        
        return ans;
    }
};


int main(){
    Solution solve;
    vector<int> ans = solve.countBits(25);
    
    
    for_each(ans.begin(), ans.end(), [](int num){
        cout<<num<<endl;
    });
    
    return 0;
}
