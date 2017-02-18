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
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

/**
 
 492. Construct the Rectangle Add to List
 
 For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
 
 1. The area of the rectangular web page you designed must equal to the given target area.
 
 2. The width W should not be larger than the length L, which means L >= W.
 
 3. The difference between length L and width W should be as small as possible.
 You need to output the length L and the width W of the web page you designed in sequence.
 Example:
 Input: 4
 Output: [2, 2]
 Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1].
 But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.
 Note:
 The given area won't exceed 10,000,000 and is a positive integer
 The web page's width and length you designed must be positive integers.
 
 */


/**
 
 50 / 50 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans;
        
        int w = sqrt(area);
        if(w * w == area){
            ans.push_back(w);
            ans.push_back(w);
        } else {
            for(int j=w;j>0;j--){
                if(area % j == 0){
                    ans.push_back(area/j);
                    ans.push_back(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};
int main(){
    
    return 0;
}
