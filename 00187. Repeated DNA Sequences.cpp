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
#include <map>
#include <set>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;

/*
 
 187. Repeated DNA Sequences
 
 Total Accepted: 59524
 Total Submissions: 206724
 Difficulty: Medium
 Contributors: Admin
 All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 
 Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 
 For example,
 
 Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 
 Return:
 ["AAAAACCCCC", "CCCCCAAAAA"].
 Subscribe to see which companies asked this question
 
 */


/*
 
 #1. use customize hash map<int,int>
 32 / 32 test cases passed.
 Status: Accepted
 Runtime: 465 ms
 
 
 #2. use map<string,int>
 Submission Details
 32 / 32 test cases passed.
 Status: Accepted
 Runtime: 555 ms
 
 #3. use customize hash without map
 32 / 32 test cases passed.
 Status: Accepted
 Runtime: 16 ms
 
 */



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        
        int key = 0;
        unsigned hashTable[1<<20] = {0}; // 0x00000-0xfffff
        for(int i=0; i<s.length();i++){
            
            key = (key << 2 | (s[i]+1)%5) & 0xfffff;
            if(i < 9) continue;
            
            if(hashTable[key] == 1){
                ans.push_back(s.substr(i-9,10));
            }
            
            hashTable[key]++;
        }
        
        return ans;
    }
    
};

int main(){
    Solution *solve = new Solution();
    
    vector<string> ans = solve->findRepeatedDnaSequences("CCCCCCACCCCCCCCCCCCCCACCC");
    
    for_each(ans.begin(), ans.end(), [](const string s){
        cout<<s<<endl;
    });
    
    
    delete solve;
    
    return 0;
}
