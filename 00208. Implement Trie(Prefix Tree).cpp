/**
 Status: Accepted
 Runtime: 84 ms
 Submitted: 1 year, 2 months ago
*/
const int Trie_Node_Max(26);

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        memset(childNode, NULL, sizeof(TrieNode *)*Trie_Node_Max);
    }
    TrieNode *childNode[Trie_Node_Max];
    bool isWord;
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        if(word.length() == 0) return;
        addTrieNode(root, word, 0);
    }
    
    
    
    // Returns if the word is in the trie.
    bool search(string word) {
        if(word.length() == 0) return true;
        
        
        return searchWord(root,word,0);
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.length() == 0) return true;
        
        return hasPrefix(root, prefix, 0);
    }
    
private:
    void addTrieNode(TrieNode* root, string word, int idx){
        int k = word[idx] - 'a';
        
        if(root->childNode[k] == NULL){
            root->childNode[k] = new TrieNode();
        }
        
        if(idx == word.length() - 1){
            root->childNode[k]->isWord = true;
        }
        else{
            addTrieNode(root->childNode[k], word, idx+1);
        }
    }
    
    bool searchWord(const TrieNode* root, const string word,int idx){
        
        int k = word[idx] - 'a';
        
        if(root->childNode[k]){
            if (idx == word.length() - 1) {
                return root->childNode[k]->isWord;
            }
            else{
                return searchWord(root->childNode[k], word, idx+1);
            }
        }
        
        return false;
    }
    
    bool hasPrefix(const TrieNode* root, const string prefix,int idx){
        int k = prefix[idx] - 'a';
        
        if(root->childNode[k]){
            if(idx == prefix.length() - 1){
                return true;
            }
            else{
                return hasPrefix(root->childNode[k], prefix, idx+1);
            }
        }
        
        return false;
    }
    TrieNode* root;
};
