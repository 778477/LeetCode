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
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;


/**
 524. Longest Word in Dictionary through Deleting
 
 Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
 
 Example 1:
 Input:
 s = "abpcplea", d = ["ale","apple","monkey","plea"]
 
 Output:
 "apple"
 Example 2:
 Input:
 s = "abpcplea", d = ["a","b","c"]
 
 Output:
 "a"
 Note:
 All the strings in the input will only contain lower-case letters.
 The size of the dictionary won't exceed 1,000.
 The length of all the strings in the input won't exceed 1,000.
 
 
 */

/**
 
 31 / 31 test cases passed.
 Status: Accepted
 Runtime: 124 ms
 
 */

class Solution {
public:
    bool isSuqstr(const string s, const string w){
        int i = 0;
        
        for(auto j=0;j<s.size() && i<w.size();++j){
            if(s[j] == w[i]){
                ++i;
            }
        }
        
        return i == w.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        
        sort(d.begin(), d.end(), [&](const string a, const string b){
            if(a.length() == b.length()) return a < b;
            
            return a.length() > b.length();
        });
        
        
        for(string word : d){
            if(isSuqstr(s,word)){
                return word;
            }
        }
        
        return "";
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    Solution solve;
    vector<string> ws = {"ale","apple","monkey","plea"};
    cout<<solve.findLongestWord("abpcplea", ws)<<endl;
    return 0;
}

