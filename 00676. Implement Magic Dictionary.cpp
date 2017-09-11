//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <unordered_map>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;



/**
 
 
 
 676. Implement Magic Dictionary
 
 Implement a magic directory with buildDict, and search methods.
 
 For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.
 
 For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.
 
 Example 1:
 Input: buildDict(["hello", "leetcode"]), Output: Null
 Input: search("hello"), Output: False
 Input: search("hhllo"), Output: True
 Input: search("hell"), Output: False
 Input: search("leetcoded"), Output: False
 Note:
 You may assume that all the inputs are consist of lowercase letters a-z.
 For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
 Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
 
 
 */


/**
 
 字典树的变种， 陷入了依赖test case修改逻辑的怪圈之中。
 
 暴力 枚举可替换的index，然后遍历字典树查找是否有对应的字符串存在。
 
 32 / 32 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 
 */


class TrieTree{
    static const unsigned CHARSETCNT = 26;
    private:
    class TrieNode{
        public:
        TrieNode *node[CHARSETCNT];
        bool isWord;
    };
    void insertWord(TrieNode* root,const int step, const string str){
        
        unsigned idx = str[step] - 'a';
        if(!root->node[idx]){
            root->node[idx] = new TrieNode();
        }
        
        
        if(step == str.size() - 1){
            root->node[idx]->isWord = true;
        } else {
            insertWord(root->node[idx], step+1, str);
        }
    }
    bool searchWord(TrieNode* root,const int step,const string str){
        unsigned idx = str[step] - 'a';
        
        if(!root->node[idx]) return false;
        if(step == str.size() - 1) return root->node[idx]->isWord;
        
        return searchWord(root->node[idx], step+1, str);
    }
    
    bool fuzzySearchWord(TrieNode *root,const unsigned step, const unsigned fazzyCount,const string str){
        if(step >= str.size()) return false;
        if(fazzyCount == 0) return searchWord(root, step, str);
        
        unsigned idx = str[step] - 'a';
        
        // try fuzzy
        bool flag = false;
        for(unsigned i = 0; i < CHARSETCNT; ++i){
            if(!root->node[i]) continue;
            if(i != idx){
                if(step == str.size() - 1 && root->node[i]->isWord) flag = true;
                flag = flag || fuzzySearchWord(root->node[i], step+1, fazzyCount - 1, str);
            }
        }
        if(flag) return flag;
        // miss fuzzy return false
        if(!root->node[idx]) return false;
        
        return fuzzySearchWord(root->node[idx], step+1, fazzyCount, str);
    }
    public:
    TrieNode *root;
    
    TrieTree(){
        root = new TrieNode();
    }
    
    ~TrieTree(){
        delete root;
    }
    
    
    void insertWord(const string str){
        if(str.size() < 1) return ;
        
        insertWord(this->root, 0, str);
    }
    
    
    bool searchWord(const string str){
        if(str.size() < 1) return true;
        
        return searchWord(this->root, 0, str);
    }
    
    /**
     支持 模糊 查询
     
     @param str 目标串
     @param count 模糊miss次数
     @return 是否命中
     */
    bool fuzzySearchWord(const string str,const unsigned count){
        if(str.size() < 1) return true;
        return fuzzySearchWord(this->root, 0, count, str);
    }
};

class MagicDictionary {
    public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        tree = new TrieTree();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        
        for_each(dict.begin(), dict.end(), [&](const string str){
            this->tree->insertWord(str);
        });
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return this->tree->fuzzySearchWord(word, 1);
    }
    private:
    TrieTree *tree;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */


/*
 
 
 // test case 26/32 Wrong Answer
 ["MagicDictionary",
 "buildDict",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search",
 "search"]
 
 [[],
 [["a","b","ab","abc","abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj","abcdefghijawefe",\
 "aefawoifjowajfowafjeoawjfaow","cba","cas","aaewfawi","babcda","bcd","awefj"]],
 
 ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["ab"], ["ba"], ["abc"], ["cba"], ["abb"], ["bb"], ["aa"], ["bbc"], ["abcd"]]
 
 
 Expected: [true,true,true,true,true,true,false,false,false,false,true,true,true,true,false]
 */

int main(){
    MagicDictionary *dict = new MagicDictionary();
    
    vector<string> strs = {"a","b","ab","abc","abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj",\
        "abcdefghijawefe","aefawoifjowajfowafjeoawjfaow","cba","cas","aaewfawi",\
        "babcda","bcd","awefj"};
    
    dict->buildDict(strs);
    
    cout<<dict->search("a")<<endl;
    cout<<dict->search("b")<<endl;
    cout<<dict->search("c")<<endl;
    cout<<dict->search("d")<<endl;
    cout<<dict->search("e")<<endl;
    cout<<dict->search("f")<<endl;
    cout<<dict->search("ab")<<endl;
    cout<<dict->search("ba")<<endl;
    cout<<dict->search("abc")<<endl;
    cout<<dict->search("cba")<<endl;
    cout<<dict->search("abb")<<endl;
    cout<<dict->search("bb")<<endl;
    cout<<dict->search("aa")<<endl;
    cout<<dict->search("bbc")<<endl;
    cout<<dict->search("abcd")<<endl;
    
    
    
    delete dict;
    return 0;
}

