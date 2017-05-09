//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
 
 575. Distribute Candies
 
 Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
 
 Example 1:
 Input: candies = [1,1,2,2,3,3]
 Output: 3
 Explanation:
 There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
 Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too.
 The sister has three different kinds of candies.
 Example 2:
 Input: candies = [1,1,2,3]
 Output: 2
 Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1].
 The sister has two different kinds of candies, the brother has only one kind of candies.
 Note:
 
 The length of the given array is in range [2, 10,000], and will be even.
 The number in given array is in range [-100,000, 100,000].
 Subscribe to see which companies asked this question.
 
 */

/*
 
 map
 207 / 207 test cases passed.
 Status: Accepted
 Runtime: 368 ms
 
 set
 207 / 207 test cases passed.
 Status: Accepted
 Runtime: 362 ms
 
 unordered_map
 207 / 207 test cases passed.
 Status: Accepted
 Runtime: 295 ms
 
 bit array
 207 / 207 test cases passed.
 Status: Accepted
 Runtime: 222 ms
 
 */


const int N = 100000;
bool vis[2*N];

class Solution {
    public:
    int distributeCandies(vector<int>& candies) {
        
        memset(vis, false, sizeof(bool)*2*N);
        int cnt = 0;
        
        for(int c : candies){
            int v = c < 0 ? N-c : c;
            
            if(!vis[v]) ++cnt;
            vis[v] = true;
        }
        
        if(cnt > candies.size()/2) cnt = (int)candies.size()/2;
        
        return cnt;
    }
};


int main(){
    
    
    
    return 0;
}
