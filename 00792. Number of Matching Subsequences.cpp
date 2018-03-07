//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 792. Number of Matching Subsequences
 
 Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
 
 Example :
 Input:
 S = "abcde"
 words = ["a", "bb", "acd", "ace"]
 Output: 3
 Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
 Note:
 
 All words in words and S will only consists of lowercase letters.
 The length of S will be in the range of [1, 50000].
 The length of words will be in the range of [1, 5000].
 The length of words[i] will be in the range of [1, 50].
 
 */

/**
 
 49 / 49 test cases passed.
 Status: Accepted
 Runtime: 394 ms
 
 维护 一个字母到有序下标序列的映射， 每次查找大于或等于该字母的下标是否存在即可。
 
 复杂度是
 NM*logk
 N是words 数组长度
 M是words[i] 字符串长度
 k是S 26个字母出现的次数
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;


class Solution {
    public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;
        
        map<char,vector<unsigned> *> m;
        
        for(unsigned i = 0; i < S.length(); ++i){
            if(!m[S[i]]){
                m[S[i]] = new vector<unsigned>();
            }
            m[S[i]]->push_back(i);
        }
        
        bool find = false;
        int idx = 0;
        for(string str : words){
            find = true;
            idx = -1;
            for(int i = 0;i<str.length();++i){
                idx = max(idx+1, i);
                
                if(!m[str[i]]){
                    find = false;
                    break;
                }
                
                unsigned cidx = (unsigned)(lower_bound(m[str[i]]->begin(), m[str[i]]->end(), idx) - m[str[i]]->begin());
                if(cidx == m[str[i]]->size()){
                    find = false;
                    break;
                }
                
                idx = m[str[i]]->at(cidx);
            }
            
            
            if(find){
                ++ans;
            }
        }
        
        return ans;
    }
};

/**
 
 46 / 49 test cases passed.
 Status: Wrong Answer
 
 Input:
 "btovxbkumc"
 ["btovxbku","to","zueoxxxjme","yjkclbkbtl"]
 
 Output:
 1
 
 Expected:
 2
 
 */

int main(int argc, const char * argv[]) {
    
    vector<string> words{"btovxbku","to","acd","ace"};
    Solution solve;
    cout<<solve.numMatchingSubseq("btovxbkumc",words)<<endl;
    
    
    return 0;
}

