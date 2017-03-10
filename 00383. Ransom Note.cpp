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
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 383. Ransom Note
 
 Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 
 Each letter in the magazine string can only be used once in your ransom note.
 
 Note:
 You may assume that both strings contain only lowercase letters.
 
 canConstruct("a", "b") -> false
 canConstruct("aa", "ab") -> false
 canConstruct("aa", "aab") -> true
 
 
 */


/**
 
 String
 
 126 / 126 test cases passed.
 Status: Accepted
 Runtime: 22 ms
 
 */

class Solution {
private:
    const int LITTERCHARCONT = 26;
public:
    bool canConstruct(string ransomNote, string magazine) {
        unsigned noteTable[LITTERCHARCONT],magazineTable[LITTERCHARCONT];
        memset(noteTable, 0, sizeof(unsigned) * LITTERCHARCONT);
        memset(magazineTable, 0, sizeof(unsigned) * LITTERCHARCONT);
        
        for(char ch : ransomNote) ++noteTable[ch-'a'];
        for(char ch : magazine) ++magazineTable[ch - 'a'];
        
        for(int i=0;i<LITTERCHARCONT;i++)
            if(noteTable[i] > magazineTable[i]) return false;
        
        return true;
    }
};


int main(){
    
    
    
    return 0;
}
