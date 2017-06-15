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
 
 162. Find Peak Element
 
 A peak element is an element that is greater than its neighbors.
 
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 
 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 
 You may imagine that num[-1] = num[n] = -∞.
 
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 
 */


/*
 58 / 58 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 */





int judge(const int *nums,int judgeIdx,int numsSize){
    if(judgeIdx == 0){
        if(numsSize == 1 || nums[judgeIdx] > nums[judgeIdx + 1]) return judgeIdx;
    } else if(judgeIdx == numsSize - 1){
        if(numsSize == 1 || nums[judgeIdx] > nums[judgeIdx - 1]) return judgeIdx;
    }
    return -1;
}


int binaryFinfPeakElement(const int *nums,int star,int end,int numsSize){
    int mid = star + ((end - star) >> 1);
    
    if(judge(nums,mid,numsSize) != -1) return mid;
    if(star == end) return -1;
    
    if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
        return mid;
    }
    
    int rAns = binaryFinfPeakElement(nums, star, mid, numsSize);
    if(rAns != -1) return rAns;
    
    int lAns = binaryFinfPeakElement(nums, mid+1, end, numsSize);
    if(lAns != -1) return lAns;
    
    return -1;
}

int findPeakElement(int* nums, int numsSize) {
    return binaryFinfPeakElement(nums, 0, numsSize,numsSize);
}


int main(){
    
    return 0;
}
