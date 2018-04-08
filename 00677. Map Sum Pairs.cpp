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
 
 677. Map Sum Pairs
 
 Implement a MapSum class with insert, and sum methods.
 
 For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
 
 For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
 
 Example 1:
 Input: insert("apple", 3), Output: Null
 Input: sum("ap"), Output: 3
 Input: insert("app", 2), Output: Null
 Input: sum("ap"), Output: 5
 
 */

/**
 
 30 / 30 test cases passed.
 Status: Accepted
 Runtime: 11 ms
 
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
    
    void dfs(vector<string>& ans,TrieNode* cur,const string prefix){
        if(!cur) return;
        if(cur->isWord){
            ans.push_back(prefix);
        }
        
        for( int i=0; i<26; ++i){
            dfs(ans,cur->nodes[i],prefix+(char)('a'+i));
        }
    }
    
    vector<string> hasPrefixStrings(const string prefix){
        vector<string> ans;
        TrieNode *cur = this->root;
        
        for( char c : prefix ){
            if(!cur->nodes[c - 'a']){
                return ans;
            }
            
            cur = cur->nodes[c - 'a'];
        }
        
        dfs(ans,cur,prefix);
        
        
        return ans;
    }
    
};

class MapSum {
    private:
    Trietree *trieTree;
    unordered_map<string, int> maap;
    public:
    /** Initialize your data structure here. */
    MapSum() {
        trieTree = new Trietree();
        maap.clear();
    }
    
    void insert(string key, int val) {
        trieTree->insert(key);
        maap[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        
        vector<string> strs = trieTree->hasPrefixStrings(prefix);
        
        for(string str : strs){
            ans += maap[str];
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
    MapSum ms;
    
    ms.insert("apple", 3);
    cout<<ms.sum("ap")<<endl;
    ms.insert("app", 2);
    cout<<ms.sum("ap")<<endl;
    
    return 0;
}
