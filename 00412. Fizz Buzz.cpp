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

using namespace std;

/**
 
 412. Fizz Buzz
 
 Write a program that outputs the string representation of numbers from 1 to n.
 
 But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
 
 Example:
 
 n = 15,
 
 Return:
 [
 "1",
 "2",
 "Fizz",
 "4",
 "Buzz",
 "Fizz",
 "7",
 "8",
 "Fizz",
 "Buzz",
 "11",
 "Fizz",
 "13",
 "14",
 "FizzBuzz"
 ]
 
 */


/**
 
 8 / 8 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for(int i = 1; i <= n; i++){
            if(i%3==0 && i%5 ==0){
                ans.push_back("FizzBuzz");
            } else if(i%5==0){
                ans.push_back("Buzz");
            } else if(i%3==0){
                ans.push_back("Fizz");
            } else{
                ans.push_back(to_string(i));
            }
        }
        
        return ans;
    }
};


int main(){
    Solution solve;
    
    vector<string> ans = solve.fizzBuzz(15);
    for_each(ans.begin(), ans.end(), [](const string str){
        cout<<str<<endl;
    });
    
    return 0;
}
