//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;



/**
 
 657. Judge Route Circle
 
 Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 
 The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 
 Example 1:
 Input: "UD"
 Output: true
 Example 2:
 Input: "LL"
 Output: false
 
 */


/**
 
 
 62 / 62 test cases passed.
 Status: Accepted
 Runtime: 29 ms
 
 */

class Solution {
public:
    bool judgeCircle(string moves) {
        int hor,ver;
        hor = ver = 0;
        
        for(char move : moves){
            switch (move) {
                case 'U':
                    ver += 1;
                    break;
                case  'D':
                    ver -= 1;
                    break;
                case 'L':
                    hor -= 1;
                    break;
                case 'R':
                    hor += 1;
                    break;
                default:
                    break;
            }
        }
        
        return (hor == 0 && ver == 0);
    }
};


int main(){
    
    Solution solve;
    cout<<solve.judgeCircle("UD")<<endl;
    cout<<solve.judgeCircle("LL")<<endl;
    
    return 0;
}


