/*
[211. Add and Search Word - Data structure design](https://leetcode.com/problems/add-and-search-word-data-structure-design/)

## 题目大意：
- - -
设计一种数据结构，支持以下两种操作：
	
	1. void addWord(word)
	
	2. bool search(word)
	
`search(word)` 可以检索一个字符串 或 一个正则表达式。 其中出现的字符只有小写字母 `a-z` 和 `.`。

`.`能表示任意字母

example：

```
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

```

## 解题思路：
- - -
这是一道很裸的Trie(字典树)。 相同的题目还有[208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/])。Trie简单理解可以理解为是一个26叉树。26取决于你要支持的字符集中的字符个数。如题中要检索的单词均由 `a-z` 小写字母组成。所以个数为26。

字典树构造完成之后，其结构特点是 由根节点到叶子节点的路径是 一个完整的单词(前缀)。


```
 
 */

const unsigned TrieNodeMaxCount(26);

class TrieNode{
public:
    TrieNode(){
        isWord = false;
        memset(childNode, 0, sizeof(TrieNode *) * TrieNodeMaxCount);
    }
    
    TrieNode *childNode[TrieNodeMaxCount];
    bool isWord;
};


class Trie{
public:
    Trie(){
        root = new TrieNode();
    }
    
    
    void addWord(const string word){
        if(word.length() == 0) return;
        
        insertWord(word, root, 0);
    }
    
    bool search(const string word){
        if(word.length() == 0) return true;
        
        return searchWord(word, root, 0);
    }
    
private:
    TrieNode *root;
    
    void insertWord(const string word,TrieNode *root,unsigned idx){
        unsigned index = word[idx] - 'a';
        
        if(root->childNode[index] == NULL){
            root->childNode[index] = new TrieNode();
        }
        
        if(word.length() - idx == 1){
            root->childNode[index]->isWord = true;
        }
        else{
            insertWord(word, root->childNode[index], idx+1);
        }
    }
    
    bool searchWord(const string word,TrieNode *root,unsigned idx){
        
        char ch = word[idx];
        
        if(ch == '.'){
            if(word.length() - idx == 1){
                for(unsigned i = 0;i<TrieNodeMaxCount;i++){
                    if(root->childNode[i] != NULL && root->childNode[i]->isWord){
                        return true;
                    }
                }
            }
            else{
                for(unsigned i = 0;i<TrieNodeMaxCount;i++){
                    if(root->childNode[i] != NULL){
                        if(searchWord(word, root->childNode[i], idx+1)){
                            return true;
                        }
                    }
                }
            }
        }
        else{
            unsigned index = ch - 'a';
            if(root->childNode[index] != NULL){
                if(word.length() - idx == 1){
                    return root->childNode[index]->isWord;
                }
                return searchWord(word, root->childNode[index], idx+1);
            }
        }
        return false;
    }
};

class WordDictionary {
public:
    WordDictionary(){
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie->addWord(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
private:
    Trie *trie;
};


