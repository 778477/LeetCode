//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 65 / 65 test cases passed.
 Status: Accepted
 Runtime: 96 ms
 
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        
        
        int groupCount = (int)hand.size() / W;
        
        if(groupCount * W != hand.size()) return false;
        
        map<unsigned,unsigned> mCount; // val - count;
        
        priority_queue<int,vector<int>,greater<int>> pQ;
        
        for(int crad : hand){
            mCount[crad]++;
            
            if(mCount[crad] == 1){
                pQ.push(crad);
            }
        }
        
        
        while(groupCount --){
            int tmp = W;
            int min = -1;
            
            while (!pQ.empty()) {
                min = pQ.top();
                if(mCount[min] > 0){
                    mCount[min]--;
                    break;
                }
                
                if(mCount[min] == 0){
                    pQ.pop();
                }
                
            }
            
            while(--tmp){
                if(mCount[min+1] > 0){
                    --mCount[min + 1];
                    min = min + 1;
                } else {
                    return false;
                }
            }
            
            
        }
        
        return true;
    }
};


int main(){
    
    
    Solution solve;
    vector<int> nums ={1,1,2,2,3,3};
    cout<<solve.isNStraightHand(nums, 3)<<endl;
    
    return 0;
}
