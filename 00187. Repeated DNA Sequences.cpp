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
 
 #1. use customize hash
 32 / 32 test cases passed.
 Status: Accepted
 Runtime: 465 ms
 
 
 #2. use map<string,int>
 Submission Details
 32 / 32 test cases passed.
 Status: Accepted
 Runtime: 555 ms
 
 
 
 */



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<int,int> hashTable;
        
        
        int letterLongLimit = 10;
        if(s.length() <= letterLongLimit) return ans;
        
        for(int i=0; i<=s.length() - letterLongLimit;i++){
            string subStr = s.substr(i,letterLongLimit);
            
            int hashNum = hashDNASequence(subStr);
            
            if(hashTable[hashNum] < 3){// more than once
                hashTable[hashNum]++;
                if(hashTable[hashNum] == 2){
                    ans.push_back(subStr);
                }
            }
            
        }
        
        
        return ans;
    }
    
private:
    int hashDNASequence(const string s){
        int hashNum = 0;
        
        for(int i=0;i<s.length();i++){
            int bitVal = 0;
            switch (s[i]) {
                case 'A':
                    bitVal = 1;
                    break;
                case 'C':
                    bitVal = 2;
                    break;
                case 'G':
                    bitVal = 3;
                    break;
                case 'T':
                    bitVal = 4;
                    break;
                default:
                    break;
            }
            
            hashNum = hashNum + bitVal * pow(4, i);
            
        }
        
        return hashNum;
    }
};

int main(){
    Solution *solve = new Solution();
    
    vector<string> ans = solve->findRepeatedDnaSequences("TTCAAAACTTTGTGGGAGCATGCTCCCATGTGGGCCAACCGCGGCGGGCCATCTTTAAATACGAAACCCAA");
    
    for_each(ans.begin(), ans.end(), [](const string s){
        cout<<s<<endl;
    });
    
    
    delete solve;
    
    return 0;
}
