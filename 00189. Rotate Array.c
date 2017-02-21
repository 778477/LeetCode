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
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 189. Rotate Array
 
 Rotate an array of n elements to the right by k steps.
 
 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 
 Note:
 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 
 
 Hint:
 Could you do it in-place with O(1) extra space?
 
 */

/**
 
 Array
 
 33 / 33 test cases passed.
 Status: Accepted
 Runtime: 269 ms
 
 */

void mySwap(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    
    int tmp;
    while(k--){
        tmp = nums[0];
        nums[0] = nums[numsSize - 1];
        nums[numsSize - 1] = tmp;
        for(int i=1;i<numsSize;i++){
            mySwap(&nums[numsSize - 1], &nums[i]);
        }
    }
}

int main(){
    int nums[] = {1,2,3,4,5,6,7};
    rotate(nums, 7, 6);
    
    for(int num : nums){
        printf("%d ",num);
    }
    printf("\n");
}



