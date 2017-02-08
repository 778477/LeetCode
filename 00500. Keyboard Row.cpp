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
#include <map>

using namespace std;

/**
 
 500. Keyboard Row
 
 Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
 
 
 American keyboard
 
 
 Example 1:
 Input: ["Hello", "Alaska", "Dad", "Peace"]
 Output: ["Alaska", "Dad"]
 
 */


/**
 
 22 / 22 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */

class Solution {
public:
    Solution(){
        keyboard['q'] = keyboard['w']  = keyboard['e'] = keyboard['r'] = keyboard['t'] = keyboard['y'] = keyboard['u'] = keyboard['i'] = keyboard['o'] = keyboard['p'] = 1;
        keyboard['a'] = keyboard['s'] = keyboard['d'] = keyboard['f'] = keyboard['g'] = keyboard['h'] = keyboard['j'] = keyboard['k'] = keyboard['l'] = 2;
        keyboard['z'] = keyboard['x'] = keyboard['c'] = keyboard['v'] = keyboard['b'] = keyboard['n'] = keyboard['m'] = 3;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        bool isRow = true;
        int row = -1;
        for(int i=0;i<words.size();i++){
            isRow = true;
            row = -1;
            for(int j=0;j<words[i].size();j++){
                char ch = words[i][j];
                if(ch < 97){
                    ch+=32;
                }
                
                if(row == -1){
                    row = keyboard[ch];
                } else if(row != keyboard[ch]){
                    isRow = false;
                    break;
                }
            }
            
            if(isRow){
                ans.push_back(words[i]);
            }
        }
        
        
        return ans;
    }
    
private:
    map<char,int> keyboard;
};


int main(){
    Solution solve;
    vector<string> words({"Hello","Alaska","Dad","Peace"});
    vector<string> ans = solve.findWords(words);
    for_each(ans.begin(), ans.end(), [](const string str){
        cout<<str<<endl;
    });
    
    return 0;
}
