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
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 393. UTF-8 Validation
 
 A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
 
 For 1-byte character, the first bit is a 0, followed by its unicode code.
 For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
 This is how the UTF-8 encoding would work:
 
 Char. number range  |        UTF-8 octet sequence
    (hexadecimal)    |              (binary)
 --------------------+---------------------------------------------
 0000 0000-0000 007F | 0xxxxxxx
 0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 Given an array of integers representing the data, return whether it is a valid utf-8 encoding.
 
 Note:
 The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.
 
 Example 1:
 
 data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
 
 Return true.
 It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
 Example 2:
 
 data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.
 
 Return false.
 The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
 The next byte is a continuation byte which starts with 10 and that's correct.
 But the second continuation byte does not start with 10, so it is invalid.
 
 */


/**
 
 49 / 49 test cases passed.
 Status: Accepted
 Runtime: 23 ms
 
 */



class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        size_t len = data.size();
        
        for( auto i = 0; i<len; i++ ){
            if((data[i]|0x7f) == 0x7f) continue;
            
            int cnt = 0;
            for(int j=0;j<3;j++){
                if((data[i]&mask[j]) == val[j]){
                    cnt = j+2;
                    break;
                }
            }
            
            if(!cnt) return false;
            if(i+cnt > len) return false;
            
            for(int j=1;j<cnt;j++){
                if((data[i+j]&0xc0) != 0x80) return false;
            }
            
            
            i += (cnt - 1);
        }
        
        return true;
    }
    
private:
    int mask[3] = {0xe0,0xf0,0xf8}; // 2,3,4
    int  val[3] = {0xc0,0xe0,0xf0};
};


int main(){
    Solution solve;
    vector<int> data;
    data.push_back(248);
    data.push_back(130);
    data.push_back(130);
    data.push_back(130);
    
    cout<<solve.validUtf8(data)<<endl;
    
    return 0;
}
