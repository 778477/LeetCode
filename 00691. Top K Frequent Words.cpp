//
//  main.cpp
//  leetcode-whiteboard
//
//  Created by miaoyou.gmy
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//



/**
 
 692. Top K Frequent Words
 
 Given a non-empty list of words, return the k most frequent elements.
 
 Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
 
 Example 1:
 Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 Output: ["i", "love"]
 Explanation: "i" and "love" are the two most frequent words.
 Note that "i" comes before "love" due to a lower alphabetical order.
 Example 2:
 Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
 Output: ["the", "is", "sunny", "day"]
 Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
 with the number of occurrence being 4, 3, 2 and 1 respectively.
 Note:
 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 Input words contain only lowercase letters.
 Follow up:
 Try to solve it in O(n log k) time and O(n) extra space.
 
 
 */

/**
 
 110 / 110 test cases passed.
 Status: Accepted
 Runtime: 13 ms
 
 */
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        
        for(auto i : words){
            ++cnt[i];
        }
        
        auto comp = [](pair<int, string> a,pair<int, string> b) -> bool {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        
        
        priority_queue<pair<int, string>,vector<pair<int, string>>,decltype(comp)> q(comp);
        
        for(auto i : cnt){
            q.push(make_pair(i.second, i.first));
        }
        
        while(k--){
            if(q.empty()) break;
            
            ans.push_back(q.top().second);
            q.pop();
        }
        
        
        
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solve;
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> ans = solve.topKFrequent(words, 4);
    for(auto i : ans){
        cout<<i<<endl;
    }
    
    return 0;
}
