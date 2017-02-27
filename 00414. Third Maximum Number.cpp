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
#include <queue>


using namespace std;

/**
 
 414. Third Maximum Number
 
 Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 
 Example 1:
 Input: [3, 2, 1]
 
 Output: 1
 
 Explanation: The third maximum is 1.
 Example 2:
 Input: [1, 2]
 
 Output: 2
 
 Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 Example 3:
 Input: [2, 2, 3, 1]
 
 Output: 1
 
 Explanation: Note that the third maximum here means the third maximum distinct number.
 Both numbers with value 2 are both considered as second maximum.
 
 
 */


/**
 
 26 / 26 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */


int thirdMax(int* nums, int numsSize) {
    int a,b,c,d;
    a = nums[0];
    b = c = d = 0;
    
    for(int i=1;i<numsSize;i++){
        if(nums[i] > a) a = nums[i];
    }
    
    for(int i = 0;i<numsSize;i++){
        if(nums[i] < a && (d == 0 || nums[i] > b)){
            b = nums[i];
            d = 1;
        }
    }
    
    d = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] < b && (d == 0 || nums[i] > c)){
            c = nums[i];
            d = 1;
        }
    }
    
    if(!d) return a;
    
    return c;
}

int main(){
    int nums[] = {1,2,-2147483648};
    
    printf("%d\n",thirdMax(nums, 3));
    
    return 0;
}
