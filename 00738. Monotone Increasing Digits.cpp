
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
using namespace std;

/**
 
 738. Monotone Increasing Digits
 
 Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
 
 (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
 
 Example 1:
 Input: N = 10
 Output: 9
 Example 2:
 Input: N = 1234
 Output: 1234
 Example 3:
 Input: N = 332
 Output: 299
 Note: N is an integer in the range [0, 10^9].
 
 
 */



/**
 
 302 / 302 test cases passed.
 Status: Accepted
 Runtime: 9 ms
 
 */
class Solution {
    public:
    
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int i = 0;
        for(i = 1; i < (int)str.length(); ++i){
            if(str[i-1] > str[i]) break;
        }
        
        if(i == (int)str.length()) return N;
        
        int tmp = i;
        while(tmp < str.length()){
            str[tmp++] = '9';
        }
        
        tmp = i-1;
        while( tmp > -1 ){
            int val = str[tmp] - '0';
            --val;
            if(tmp == 0){
                str[tmp] = val > 0 ? val+'0' : '0';
                break;
            } else{
                int preVal = str[tmp - 1] - '0';
                
                if(val >= preVal){
                    str[tmp] = val + '0';
                    break;
                } else {
                    str[tmp] = '9';
                }
            }
            --tmp;
        }
        return stoi(str);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solve;
    
    vector<int> nums = { 1234, 10, 332, 4321, 111, 54378, 567431, 110, 10000, 987777432, 00001, 12221, 198, 9, 919};
    
    for(int num : nums){
        cout<<num<<" monotoneIncreasingDigits is "<<solve.monotoneIncreasingDigits(num)<<endl;
    }
    
    
    return 0;
}
