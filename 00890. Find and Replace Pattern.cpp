//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 890. Find and Replace Pattern
 
 You have a list of words and a pattern, and you want to know which words in words matches the pattern.
 
 A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
 
 (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
 
 Return a list of the words in words that match the given pattern.
 
 You may return the answer in any order.
 
 
 
 Example 1:
 
 Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 Output: ["mee","aqq"]
 Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
 "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
 since a and b map to the same letter.
 
 
 Note:
 
 1 <= words.length <= 50
 1 <= pattern.length = words[i].length <= 20
 */

/**
 
 46 / 46 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();
class Solution {
public:
    map<char, vector<unsigned> *> getCounter(const string str){
        map<char, vector<unsigned> *> counter;
        
        for(unsigned i = 0;i<str.length(); ++i){
            if(!counter[str[i]]){
                counter[str[i]] = new vector<unsigned>();
            }
            counter[str[i]]->push_back(i);
        }
        return counter;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        auto patternCount = this->getCounter(pattern);
        
        for(string str : words){
            auto counter = this->getCounter(str);
            if(patternCount.size() != counter.size()) {
                continue;
            }
            
            
            bool flag = true;
            vector<bool> visable(str.length(),false);
            for(unsigned i = 0; i<str.length() && flag; ++i){
                if(visable[i]){
                    continue;
                }
                
                if(!patternCount[pattern[i]] || patternCount[pattern[i]]->size() != counter[str[i]]->size()){
                    flag = false;
                    continue;
                }
                
                for(unsigned j = 0;j<counter[str[i]]->size(); ++j){
                    if( (*counter[str[i]])[j] != (*patternCount[pattern[i]])[j] ){
                        flag = false;
                        break;
                    }
                    visable[(*counter[str[i]])[j]] = true;
                }
            }
            
            if(flag){
                ans.push_back(str);
            }
            
        }
        
        return ans;
    }
};

/**
 
 ["yzmyr","fhufq","lghlq","oahot","ueiuq"]
 "iusiq"
 
 ["badc","abab","dddd","dede","yyxx"]
 "baba"
 
 ["ab","cd","fe","gg"]
 "ab"
 
 ["qxrwtncxyoqwmsxoavos","eqvzjrnqgkezxmqkhdkm","pjxmgdujohpmtsjhazhs","yqhlipeqwnylkrqnsbnr","plktdyslmoptqflowaof"]
 "ghtxpauhingxekhnoqnk"
 
 ["ktittgzawn","dgphvfjniv","gceqobzmis","alrztxdlah","jijuevoioe","mawiizpkub","onwpmnujos","zszkptjgzj","zwfvzhrucv","isyaphcszn"]
 "zdqmjnczma"
 
 */


int main(){
    
    Solution solve;
    vector<string> words = {"ktittgzawn","dgphvfjniv","gceqobzmis","alrztxdlah","jijuevoioe","mawiizpkub","onwpmnujos","zszkptjgzj","zwfvzhrucv","isyaphcszn"};
    vector<string> ans = solve.findAndReplacePattern(words, "zdqmjnczma");
    
    for(string str : ans){
        cout<<str<<endl;
    }
    
    return 0;
}


