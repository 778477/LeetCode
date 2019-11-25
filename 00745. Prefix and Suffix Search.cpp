#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;
/** 
745. Prefix and Suffix Search

Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). 
It will return the word with given prefix and suffix with maximum weight. 
If no word exists, return -1.

Note:

words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.
 */


class Trie{
    class TrieNode{
    public:
        TrieNode *nodes[26];
        vector<int> vals;
    };
public:
    Trie(){
        root = new TrieNode();
    }

    void build(const string& word, const int val){
        TrieNode *cur = this->root;
        cur->vals.push_back(val);
        for(auto c : word){
            int idx = c - 'a';
            if(!cur->nodes[idx]){
                cur->nodes[idx] = new TrieNode();
            }
            cur = cur->nodes[idx];
            cur->vals.push_back(val);
        }
    }

    vector<int> search(const string& prefix){
        TrieNode *cur = root;
        for(auto c : prefix){
            cur = cur->nodes[c - 'a'];
            if(!cur) {
                return {};
            }
        }
        return cur->vals;
    }
private:
    TrieNode *root;
};

class WordFilter {
public:
    Trie *_prefix, *_suffix;
    WordFilter(vector<string>& words) {
        _suffix = new Trie();
        _prefix = new Trie();

        for(int i = (int)words.size() - 1; i>-1; --i){
            string word = words[i];
            _prefix->build(word, i);
            reverse(word.begin(), word.end());
            _suffix->build(word, i);
        }
    }
    
    int f(string prefix, string suffix) {

        vector<int> prefixVals = _prefix->search(prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> suffixVals = _suffix->search(suffix);

        if(suffixVals.size() < 1 || prefixVals.size() < 1){
            return -1;
        }
        int i = 0, j = 0;
        while( i < prefixVals.size() && j < suffixVals.size() ){
            if( prefixVals[i] == suffixVals[j] ) return prefixVals[i];
            else if( prefixVals[i] < suffixVals[j] ){
                ++j;
            } else {
                ++i;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 * ["WordFilter","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f","f"]
  [[["pop"]],
  ["",""],
  ["","p"],
  ["","op"],
  ["","pop"],
  ["p",""],["p","p"],["p","op"],["p","pop"],["po",""],["po","p"],["po","op"],["po","pop"],["pop",""],["pop","p"],["pop","op"],["pop","pop"],["",""],["","p"],["","gp"],["","pgp"],["p",""],["p","p"],["p","gp"],["p","pgp"],["pg",""],["pg","p"],["pg","gp"],["pg","pgp"],["pgp",""],["pgp","p"],["pgp","gp"],["pgp","pgp"]]

    ["","abaa"],
    ["babbab",""],
    ["ab","baaa"],
    ["baaabba","b"],
    ["abab","abbaabaa"],
    ["","aa"],
    ["","bba"],
    ["","baaaaabbbb"],
    ["ba","aabbbb"],
    ["baaa","aabbabbb"]]
 */
int main(){
    vector<string> words = {"abbbababbb","baaabbabbb","abababbaaa","abbbbbbbba","bbbaabbbaa","ababbaabaa","baaaaabbbb","babbabbabb","ababaababb","bbabbababa"};
    WordFilter *filter = new WordFilter(words);
    cout<<filter->f("","abaa")<<endl;
    cout<<filter->f("babbab","")<<endl;
    cout<<filter->f("ab","baaa")<<endl;
    cout<<filter->f("baaabba","b")<<endl;
    cout<<filter->f("abab","abbaabaa")<<endl;
    cout<<filter->f("","aa")<<endl;
    cout<<filter->f("","bba")<<endl;
    cout<<filter->f("","baaaaabbbb")<<endl;
    cout<<filter->f("ba","aabbbb")<<endl;
    cout<<filter->f("baaa","aabbabbb")<<endl;
    return 0;
}
