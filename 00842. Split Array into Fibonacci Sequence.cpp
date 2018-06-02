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
#include <queue>
#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 842. Split Array into Fibonacci Sequence
 
 Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].
 
 Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:
 
 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
 F.length >= 3;
 and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
 Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
 
 Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.
 
 Example 1:
 
 Input: "123456579"
 Output: [123,456,579]
 Example 2:
 
 Input: "11235813"
 Output: [1,1,2,3,5,8,13]
 Example 3:
 
 Input: "112358130"
 Output: []
 Explanation: The task is impossible.
 Example 4:
 
 Input: "0123"
 Output: []
 Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
 Example 5:
 
 Input: "1101111"
 Output: [110, 1, 111]
 Explanation: The output [11, 0, 11, 11] would also be accepted.
 Note:
 
 1 <= S.length <= 200
 S contains only digits.
 
 */


/**
 
 
 70 / 70 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 
 */

class Solution {
public:
    
    int dfs(long pre,long sum,const string& buf,int index,int step){
        if(index >= buf.length()){
            return step;
        }
        
        string tmp = to_string(sum);
        
        
        for(size_t i = 0;i<tmp.length(); ++i){
            if(tmp[i] != buf[index + i]) return -1;
        }
        
        if(pre + sum > INT_MAX && (buf.length() - index > tmp.length())){
            return -1;
        }
        
        return dfs(sum,pre+sum,buf,index + (int)tmp.length(), step+1);
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        
        
        for(int i=1;i<=(int)S.length(); ++i){
            string firstSubStr = S.substr(0,i);
            // ignore Leading zeroes
            if(firstSubStr[0] == '0' && firstSubStr.length() > 1) continue;
            if(firstSubStr.length() > 10) continue;
            
            
            for(int j= i+1;j<=(int)S.length(); ++j){
                string secondSubStr = S.substr(i,j - i);
                // ignore Leading zeroes
                if(secondSubStr[0] == '0' && secondSubStr.length() > 1) continue;
                if(secondSubStr.length() > 10) continue;
                
                
                
                long first = stol(firstSubStr);
                long second = stol(secondSubStr);
                
                if(first > INT_MAX || second > INT_MAX || first + second > INT_MAX){
                    continue;
                }
                
                int step = dfs(second, first + second, S, j, 0);
                if(step > 0){
                    ans.push_back((int)first);
                    ans.push_back((int)second);
                    while(step--){
                        ans.push_back((int)(first + second));
                        int tmp = (int)second;
                        second = first + second;
                        first = tmp;
                    }
                    
                    return ans;
                }
                
            }
        }
        
        return ans;
    }
};


int main(){
    Solution solve;
    
    vector<int> ans = solve.splitIntoFibonacci("417420815174208193484163452262453871040871393665402264706273658371675923077949581449611550452755");
    
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
