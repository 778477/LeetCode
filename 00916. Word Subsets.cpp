//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;



/**
 
 916. Word Subsets
 
 We are given two arrays A and B of words.  Each word is a string of lowercase letters.
 
 Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".
 
 Now say a word a from A is universal if for every b in B, b is a subset of a.
 
 Return a list of all universal words in A.  You can return the words in any order.
 
 
 
 Example 1:
 
 Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
 Output: ["facebook","google","leetcode"]
 Example 2:
 
 Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
 Output: ["apple","google","leetcode"]
 Example 3:
 
 Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
 Output: ["facebook","google"]
 Example 4:
 
 Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
 Output: ["google","leetcode"]
 Example 5:
 
 Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
 Output: ["facebook","leetcode"]
 
 
 Note:
 
 1 <= A.length, B.length <= 10000
 1 <= A[i].length, B[i].length <= 10
 A[i] and B[i] consist only of lowercase letters.
 All words in A[i] are unique: there isn't i != j with A[i] == A[j].
 
 
 */

/**
 
 55 / 55 test cases passed.
 Status: Accepted
 Runtime: 68 ms
 
 */

// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        
        vector<unsigned> c(26,0);
        
        for(string b : B){
            vector<unsigned> tmp(26, 0);
            for(char bc : b){
                ++tmp[bc-'a'];
            }
            
            for(int i=0;i<26;++i){
                c[i] = max(c[i], tmp[i]);
            }
        }
        
        
        for(string a : A){
            vector<unsigned> tmp(26,0);
            for(char ac : a){
                ++tmp[ac-'a'];
            }
            
            int i = 0;
            for(;i<26;++i){
                if(tmp[i] < c[i]) break;
            }
            if(i == 26){
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    
    vector<string> A = {"amazon","apple","facebook","google","leetcode"};
    vector<string> B = {"ec","oc","ceo"};
    
    vector<string> ans = solve.wordSubsets(A, B);
    for(string str : ans) cout<<str<<endl;
    return 0;
}

