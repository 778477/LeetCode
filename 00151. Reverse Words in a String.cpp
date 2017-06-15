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
 
 
 151. Reverse Words in a String
 
 
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 Update (2015-02-12):
 For C programmers: Try to solve it in-place in O(1) space.
 
 
 */


/*
 
 
 22 / 22 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 
 */


class Solution {
private:
    vector<string> stringV;
public:
    Solution()
    {
        stringV.clear();
    }
    void reverseWords(string &s) {
        string tmp;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
                tmp.push_back(s[i]);
            else
            {
                if(tmp.length())
                {
                    stringV.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        
        if(tmp.length())
            stringV.push_back(tmp);
        s.clear();
        for(int i=(int)stringV.size()-1; i>-1; i--)
        {
            if(i == 0)
                s.append(stringV[i]);
            else
            {
                s.append(stringV[i].append(" "));
            }
        }
    }
};

int main(){
    
    return 0;
}
