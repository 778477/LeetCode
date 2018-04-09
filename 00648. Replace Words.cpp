//
//  main.cpp
//  whiteBorad-leetcode
//
//  Created by 郭妙友 on 2018/3/30.
//  Copyright © 2018年 郭妙友. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 
 648. Replace Words
 
 In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.
 
 Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.
 
 You need to output the sentence after the replacement.
 
 Example 1:
 Input: dict = ["cat", "bat", "rat"]
 sentence = "the cattle was rattled by the battery"
 Output: "the cat was rat by the bat"
 Note:
 The input will only have lower-case letters.
 1 <= dict words number <= 1000
 1 <= sentence words number <= 1000
 1 <= root length <= 100
 1 <= sentence words length <= 1000
 
 */

/**
 
 124 / 124 test cases passed.
 Status: Accepted
 Runtime: 133 ms
 
 */

class TrieNode{
    public:
    int isWord;
    TrieNode *nodes[26];
};

class Trietree{
    private:
    TrieNode *root;
    public:
    Trietree(){
        root = new TrieNode();
    }
    void insert(const string str){
        TrieNode *cur = this->root;
        for( char c : str ){
            if(!cur->nodes[c - 'a']){
                cur->nodes[c - 'a'] = new TrieNode();
            }
            cur = cur->nodes[c - 'a'];
        }
        cur->isWord = true;
    }
    
    
    unsigned shortestPrefix(const string str){
        TrieNode *cur = this->root;
        unsigned idx = 0;
        bool hasPrefix = false;
        while(cur && idx < str.size()){
            if(cur->isWord){
                hasPrefix = true;
                break;
            }
            cur = cur->nodes[str[idx++]-'a'];
        }
        
        if(!hasPrefix){
            idx = 0;
        }
        
        return idx;
    }
};

class Solution {
    private:
    Trietree *_trieTree;
    vector<string> split(const string& str, const string& delim)
    {
        vector<string> tokens;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == string::npos) pos = str.length();
            string token = str.substr(prev, pos-prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delim.length();
        }
        while (pos < str.length() && prev < str.length());
        return tokens;
    }
    
    public:
    Solution(){
        _trieTree = new Trietree();
    }
    ~Solution(){
        delete _trieTree;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        string ans;
        
        vector<string> successors = split(sentence, " ");
        for(string root : dict){
            _trieTree->insert(root);
        }
        
        vector<string> roots;
        
        for(string successor : successors){
            
            unsigned idx = _trieTree->shortestPrefix(successor);
            idx != 0 ? roots.push_back(successor.substr(0,idx)) : roots.push_back(successor);
        }
        
        for(size_t i = 0;i<roots.size();++i){
            if(i == 0){
                ans = ans + roots[i];
            } else {
                ans = ans + " " + roots[i];
            }
        }
        
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
int main(int argc, const char * argv[]) {
    Solution solve;
    vector<string> dict({"cat", "bat", "rat"});
    cout<<solve.replaceWords(dict, "the cattle was rattled by the battery")<<endl;
    
    
    return 0;
}
