//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 451. Sort Characters By Frequency
 DescriptionHintsSubmissionsDiscussSolution
 Discuss Pick One
 Given a string, sort it in decreasing order based on the frequency of characters.
 
 Example 1:
 
 Input:
 "tree"
 
 Output:
 "eert"
 
 Explanation:
 'e' appears twice while 'r' and 't' both appear once.
 So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 Example 2:
 
 Input:
 "cccaaa"
 
 Output:
 "cccaaa"
 
 Explanation:
 Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 Note that "cacaca" is incorrect, as the same characters must be together.
 Example 3:
 
 Input:
 "Aabb"
 
 Output:
 "bbAa"
 
 Explanation:
 "bbaA" is also a valid answer, but "Aabb" is incorrect.
 Note that 'A' and 'a' are treated as two different characters.

 
 */

/**
 
 35 / 35 test cases passed.
 Status: Accepted
 Runtime: 19 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for(auto c : s){
            ++cnt[c];
        }
        priority_queue<pair<int, char>> q;
        for(auto i : cnt){
            q.push(make_pair(i.second, i.first));
        }
        
        string ans = "";
        
        while(!q.empty()){
            for(auto i = 0; i<q.top().first; ++i){
                ans += q.top().second;
            }
            q.pop();
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
