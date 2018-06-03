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
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 104 / 104 test cases passed.
 Status: Accepted
 Runtime: 9 ms
 
 */

class Solution {
public:
    void backspace(string & S){
        typedef pair<char, int> letter;
        
        stack<letter> BackSpace;
        stack<letter> Letters;
        
        for (int i=0;i<S.length(); ++i){
            if(S[i] == '#'){
                BackSpace.push(make_pair(S[i], i));
            } else {
                Letters.push(make_pair(S[i], i));
            }
        }
        
        string tmp = "";
        while(!Letters.empty()){
            letter l = Letters.top();
            Letters.pop();
            
            
            if(!BackSpace.empty() && BackSpace.top().second > l.second){
                BackSpace.pop();
                continue;
            }
            
            
            tmp += l.first;
        }
        
        reverse(tmp.begin(), tmp.end());
        S = tmp;
    }
    
    bool backspaceCompare(string S, string T) {
        
        backspace(S);
        backspace(T);
        
        
        return S == T;
    }
};


int main(){
    
    
    Solution solve;
    cout<<solve.backspaceCompare("ab#c", "ad#c")<<endl;
    cout<<solve.backspaceCompare("ab##", "c#d#")<<endl;
    cout<<solve.backspaceCompare("a##c", "#a#c")<<endl;
    cout<<solve.backspaceCompare("a#c", "b")<<endl;
    
    cout<<solve.backspaceCompare("xywrrmp", "xywrrmu#p")<<endl;
    
    
    return 0;
}
