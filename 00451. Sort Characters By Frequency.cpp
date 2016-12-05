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
 
 451. Sort Characters By Frequency
 Total Accepted: 8028
 Total Submissions: 16018
 Difficulty: Medium
 Contributors: stickypens
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



/*
 
 34 / 34 test cases passed.
 Status: Accepted
 Runtime: 1005 ms
 
 
 */



class Solution {
public:
    Solution(){
        _maxFrequent = 0;
    }
    
    
    string frequencySort(string s) {
        string ans;
        
        for_each(s.begin(), s.end(), [&](const char ch){
            if(table.count(ch)){
                int oldF = table[ch];
                frequentTable[oldF].erase(iterTable[ch]);
                iterTable.erase(ch);
            }
            
            ++table[ch];
            _maxFrequent = _maxFrequent > table[ch] ? _maxFrequent : table[ch]; // update maxFrequent
            frequentTable[table[ch]].push_back(ch);
            iterTable[ch] = --frequentTable[table[ch]].end();
        });
        
        while(_maxFrequent > 0){
            
            for_each(frequentTable[_maxFrequent].begin(), frequentTable[_maxFrequent].end(), [&](const char ch){
                for(int i=0;i<_maxFrequent;i++){
                    ans.push_back(ch);
                }
            });
            
            _maxFrequent--;
        }
        
        return ans;
    }
    
    
private:
    int _maxFrequent;
    map<char,int> table;
    map<int, list<char>> frequentTable;
    map<char, list<char>::iterator> iterTable;
};


int main(){
    Solution solve;
    
    cout<<solve.frequencySort("cccaaa")<<endl;
    
    
    return 0;
}

