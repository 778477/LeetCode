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
#include <unordered_map>
#include <string>

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 504. Base 7
 
 Given an integer, return its base 7 string representation.
 
 Example 1:
 Input: 100
 Output: "202"
 
 Example 2:
 Input: -7
 Output: "-10"
 
 Note: The input will be in range of [-1e7, 1e7].
 */


/**
 
 241 / 241 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */



class Solution {
public:
    string convertToBase7(int num) {
        string ans("");
        transform(abs(num), ans);
        reverse(ans.begin(), ans.end());
        if(num < 0) return "-"+ans;
        
        return ans;
    }
    
    void transform(int num,string& str){
        if(num < BASE){
            str+=to_string(num);
            return ;
        }
        transform(num/7, str+=to_string(num%BASE));
    }
private:
    const int BASE = 7;
};



int main(){
    Solution solve;
    
    cout<<solve.convertToBase7(7)<<endl;
    cout<<solve.convertToBase7(-100)<<endl;
    
    return 0;
}
