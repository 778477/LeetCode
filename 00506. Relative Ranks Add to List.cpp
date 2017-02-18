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
 
 506. Relative Ranks Add to List
 
 Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 
 Example 1:
 Input: [5, 4, 3, 2, 1]
 Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
 For the left two athletes, you just need to output their relative ranks according to their scores.
 Note:
 N is a positive integer and won't exceed 10,000.
 All the scores of athletes are guaranteed to be unique.
 
 */


/**
 
 17 / 17 test cases passed.
 Status: Accepted
 Runtime: 13 ms
 
 */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans(nums.size());
        vector<Relative *> relatives(nums.size());
        
        for(int i = 0;i<nums.size();i++){
            relatives[i] = new Relative(nums[i],i);
        }
        
        // All the scores of athletes are guaranteed to be unique.
        sort(relatives.begin(), relatives.end(), [](const Relative *a,const Relative *b){
            return a->score > b->score;
        });
        
        for(int i=0;i<relatives.size();i++){
            if(i == 0){
                ans[relatives[i]->number] = string("Gold Medal");
            } else if(i == 1){
                ans[relatives[i]->number] = string("Silver Medal");
            } else if (i == 2){
                ans[relatives[i]->number] = string("Bronze Medal");
            } else{
                ans[relatives[i]->number] = to_string(i+1);
            }
        }
        
        
        return ans;
    }
private:
    class Relative{
    public:
        int score,number;
        Relative(int _s,int _n){
            score = _s,number = _n;
        }
    };
};
int main(){
    Solution solve;
    vector<int> nums({1,2,3,4,5});
    vector<string> ans = solve.findRelativeRanks(nums);
    
    for(string str : ans){
        cout<<str<<endl;
    }
    
    
    return 0;
}
