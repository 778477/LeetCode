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
#include <queue>
#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 
 763. Partition Labels
 
 A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
 
 Example 1:
 Input: S = "ababcbacadefegdehijhklij"
 Output: [9,7,8]
 Explanation:
 The partition is "ababcbaca", "defegde", "hijhklij".
 This is a partition so that each letter appears in at most one part.
 A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 Note:
 
 S will have length in range [1, 500].
 S will consist of lowercase letters ('a' to 'z') only.
 
 
 
 
 
 */


/**
 
 116 / 116 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */


class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        
        vector<int> markUp(26,-1);
        
        for(auto i = 0; i<S.size(); ++i){
            if(i + 1 > markUp[S[i] - 'a']){
                markUp[S[i] - 'a'] = i+1;
            }
        }
        
        int tmpMax = 1;
        for(auto i = 0; i<S.size(); ++i){
            if(markUp[S[i] - 'a'] > tmpMax){
                tmpMax = markUp[S[i] - 'a'];
            }
            
            if(i + 1 == tmpMax){
                if(ans.empty()){
                    ans.push_back(tmpMax);
                } else {
                    int sum = accumulate(ans.begin(), ans.end(), 0);
                    ans.push_back(tmpMax - sum);
                }
            }
        }
        
        
        
        
        return ans;
    }
};





int main(){
    
    
    Solution solve;
    
    vector<int> ans = solve.partitionLabels("abacdefc");
    
    for_each(ans.begin(), ans.end(), [](const int num){
        cout<<num<<endl;
    });
    
    return 0;
}
