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
 
 554. Brick Wall
 
 There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.
 
 The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.
 
 If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.
 
 You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
 
 Note:
 The width sum of bricks in different rows are the same and won't exceed INT_MAX.
 The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.
 */


/**
 
 85 / 85 test cases passed.
 Status: Accepted
 Runtime: 39 ms
 
 */



class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = 0;
        unordered_map<int, int> table;
        
        for(vector<int> w : wall){
            if(w.size() < 2) continue;
            int tmp = 0;
            for(auto i = 0;i<w.size() - 1;i++){
                tmp+=w[i];
                table[tmp]++;
                
                if(table[tmp] > ans) ans = table[tmp];
            }
        }
        
        return (int)wall.size() - ans;
    }
};
int main(){
    
    //    Solution solve;
    
    
    
    return 0;
}

