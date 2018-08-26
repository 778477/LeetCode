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
 
 893. Groups of Special-Equivalent Strings
 
 You are given an array A of strings.
 
 Two strings S and T are special-equivalent if after any number of moves, S == T.
 
 A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j].
 
 Now, a group of special-equivalent strings from A is a non-empty subset S of A such that any string not in S is not special-equivalent with any string in S.
 
 Return the number of groups of special-equivalent strings from A.
 
 
 
 Example 1:
 
 Input: ["a","b","c","a","c","c"]
 Output: 3
 Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
 Example 2:
 
 Input: ["aa","bb","ab","ba"]
 Output: 4
 Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
 Example 3:
 
 Input: ["abc","acb","bac","bca","cab","cba"]
 Output: 3
 Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
 Example 4:
 
 Input: ["abcd","cdab","adcb","cbad"]
 Output: 1
 Explanation: 1 group ["abcd","cdab","adcb","cbad"]
 
 
 Note:
 
 1 <= A.length <= 1000
 1 <= A[i].length <= 20
 All A[i] have the same length.
 All A[i] consist of only lowercase letters.
 
 */

/**
 
 34 / 34 test cases passed.
 Status: Accepted
 Runtime: 4 ms
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> group;
        for(string str : A){
            string tmp = "";
            string buf = "";
            for(auto i=0;i<str.size();i+=2){
                tmp += str[i];
            }
            sort(tmp.begin(), tmp.end());
            buf += tmp;
            tmp.clear();
            for(auto i=1;i<str.size();i+=2){
                tmp += str[i];
            }
            sort(tmp.begin(), tmp.end());
            buf += tmp;
            group.insert(buf);
        }
        return (int)group.size();
    }
};


int main(){
    
    Solution solve;
    vector<string> A = {"abcd","cdab","adcb","cbad"};
    cout<<solve.numSpecialEquivGroups(A)<<endl;
    return 0;
}


