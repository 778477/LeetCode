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
 
 401. Binary Watch
 
 A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
 
 Each LED represents a zero or one, with the least significant bit on the right.
 https://upload.wikimedia.org/wikipedia/commons/8/8b/Binary_clock_samui_moon.jpg
 
 For example, the above binary watch reads "3:25".
 
 Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
 
 Example:
 
 Input: n = 1
 Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 Note:
 The order of output does not matter.
 The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
 The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
 
 */


/**
 
 Backtracking / Bit Manipulation
 
 10 / 10 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */



class Solution {
public:
    void addTime(const vector<unsigned> nums,vector<string>& ans){
        string str;
        unsigned hour = 0;
        unsigned minu = 0;
        
        hour = hour + (nums[0] ? 8 : 0);
        hour = hour + (nums[1] ? 4 : 0);
        hour = hour + (nums[2] ? 2 : 0);
        hour = hour + (nums[3] ? 1 : 0);
        
        minu = minu + (nums[4] ? 32 : 0);
        minu = minu + (nums[5] ? 16 : 0);
        minu = minu + (nums[6] ?  8 : 0);
        minu = minu + (nums[7] ?  4 : 0);
        minu = minu + (nums[8] ?  2 : 0);
        minu = minu + (nums[9] ?  1 : 0);
        
        if(hour > 11 || minu > 59) return;
        
        str+=to_string(hour);
        str+=":";
        
        if(minu < 10) str+="0";
        str+=to_string(minu);
        
        ans.push_back(str);
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        vector<unsigned> nums(10,0);
        for(int i=0;i<num;i++) nums[9-i] = 1;
        
        addTime(nums,ans);
        while(next_permutation(nums.begin(), nums.end())){
            addTime(nums,ans);
        }
        
        return ans;
    }
    
};

int main(){
    Solution solve;
    vector<string> ans = solve.readBinaryWatch(2);
    
    for(string str : ans){
        cout<<str<<endl;
    }
    
    return 0;
}
