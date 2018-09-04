//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

/**
 
 522. Longest Uncommon Subsequence II
 
 Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
 
 A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
 
 The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
 
 Example 1:
 Input: "aba", "cdc", "eae"
 Output: 3
 Note:
 
 All the given strings' lengths will not exceed 10.
 The length of the given list will be in the range of [2, 50].
 
 
 
 */


/**
 
 98 / 98 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */

static auto _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    bool aisSubstrOfb(const string a,const string b){
        auto i=0;
        for(auto c : b){
            if(c == a[i]) ++i;
        }
        return i == a.length();
    }
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> Counter;
        for(string str : strs){
            ++Counter[str];
        }
        sort(strs.begin(), strs.end(), [&](const string a,const string b){
            if(a.length() == b.length()) return a > b;
            return a.length() > b.length();
        });
        
        for(auto i=0;i<strs.size();++i){
            if(Counter[strs[i]] > 1) continue;
            bool flag = true;
            for(auto j = 0; j< i; ++j){
                if(aisSubstrOfb(strs[i], strs[j])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return (int)strs[i].length();
            }
        }
        
        return -1;
    }
};
/**
 ["aabbcc", "aabbcc","cb"]
 
 ["abcabc","abcabc","abcabc","abc","abc","cca"]
 
 */

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    Solution solve;
    //    vector<string> strs = {"aaa","aaa","aa"};
    //    vector<string> strs = {"aabbcc", "aabbcc","cb"};
    vector<string> strs = {"aabbcc","aabbcc","bc","bcc","ab"};
    cout<<solve.findLUSlength(strs)<<endl;
    
    
    
    
    return 0;
}

