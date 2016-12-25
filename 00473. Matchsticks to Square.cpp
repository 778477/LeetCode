//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

/*
 473. Matchsticks to Square
 
 Total Accepted: 1381
 Total Submissions: 4756
 Difficulty: Medium
 Contributors: weezer
 Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
 
 Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
 
 Example 1:
 Input: [1,1,2,2,2]
 Output: true
 
 Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
 Example 2:
 Input: [3,3,3,3,4]
 Output: false
 
 Explanation: You cannot find a way to form a square with all the matchsticks.
 Note:
 The length sum of the given matchsticks is in the range of 0 to 10^9.
 The length of the given matchstick array will not exceed 15.
 Subscribe to see which companies asked this question
 **/

/*
 Accepted	36 ms	cpp
 **/
class Solution {
    public:
    bool makesquare(vector<int>& nums) {
        int total = 0;
        for_each(nums.begin(), nums.end(), [&](const int num){
            total += num;
        });
        int target = total/4;
        if(target * 4 != total || total == 0) return false;
        
        srand((int)time(NULL));
        vector<int> a;
        vector<int> b;
        int time = 500;
        while(time--){
            if(!canBin(nums, a, b, target * 2)) continue;
            vector<int> aa,bb;
            if(canBin(a, aa, bb, target) && canBin(b, aa, bb, target)) return true;
        }
        
        
        return false;
    }
    
    bool canBin(vector<int>&nums,vector<int>& a, vector<int>& b, int target){
        a.clear();
        b.clear();
        
        int suma = 0,sumb = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2) a.push_back(nums[i]),suma+=nums[i];
            else b.push_back(nums[i]),sumb+=nums[i];
        }
        
        if(suma == sumb) return true;
        int tmp = 0;
        int time = 10;
        while(time--){
            if(suma == sumb) break;
            
            if(rand()%2 && a.size()>0 && b.size()>0){
                int aidx = rand()%a.size();
                int bidx = rand()%b.size();
                
                suma = suma - a[aidx] + b[bidx];
                sumb = sumb - b[bidx] + a[aidx];
                tmp = a[aidx];
                a[aidx] = b[bidx];
                b[bidx] = tmp;
            } else{
                if(suma > sumb){
                    tmp = a.back();
                    b.push_back(a.back());
                    a.pop_back();
                    sumb += tmp;
                    suma -= tmp;
                } else{
                    tmp = b.back();
                    a.push_back(b.back());
                    b.pop_back();
                    suma += tmp;
                    sumb -= tmp;
                }
            }
            
        }
        
        return suma == sumb;
    }
};

int main(){
    
    Solution solve;
    vector<int> nums{10,6,5,5,5,3,3,3,2,2,2,2};
    
    cout<<solve.makesquare(nums)<<endl;
    
    return 0;
}
