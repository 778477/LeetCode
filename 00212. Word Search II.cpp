/**
 Status: Accepted
 Runtime: 591 ms
 Submitted: 1 year, 2 months ago
*/
const int TrieChildNodeMax(26);
class Trie{
public:
    class TrieNode{
    public:
        TrieNode(){
            isWord = false;
            word = "";
            memset(childNode, NULL, sizeof(TrieNode *) * TrieChildNodeMax);
        }
        TrieNode *childNode[TrieChildNodeMax];
        string word;
        bool isWord;
    };
    TrieNode *root;
    
    Trie(){
        root = new TrieNode();
    }
    
    
    void insert(const string word,TrieNode* node,int idx = 0){
        if(idx == word.length()) return ;
        int k = word[idx] - 'a';
        if(node->childNode[k] == NULL){
            node->childNode[k] = new TrieNode();
        }
        if(idx == word.length() - 1){
            node->childNode[k]->isWord = true;
            node->childNode[k]->word = word;
        }
        else{
            insert(word, node->childNode[k],idx+1);
        }
    }
    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        
        
        for_each(words.begin(), words.end(), [&](const string word){
            trie.insert(word, trie.root);
        });
        
        
        n = (int)board.size();
        m = 0;
        if(n > 0) m = (int)board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                memset(vis, false, sizeof(bool)*1024*1024);
                if(boardHasWord(board,i,j,trie.root,ans)){
                    //                    cout<<"Yes,find word in borad"<<endl;
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
private:
    bool judge(const int x,const int y){
        return (x>-1&&x<n&&y>-1&&y<m&&!vis[x][y]);
    }
    bool boardHasWord(const vector<vector<char>> board,int x,int y,Trie::TrieNode* root,vector<string>& ans){
        int k = board[x][y] - 'a';
        vis[x][y] = true;
        if(root->childNode[k]){
            if(root->childNode[k]->isWord){
                root->childNode[k]->isWord = false;
                ans.push_back(root->childNode[k]->word);
                // return true;
            }
            
            
            for(int i=0;i<4;i++){
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                
                if(judge(xx, yy)){
                    vis[xx][yy] = true;
                    if(boardHasWord(board, xx, yy, root->childNode[k], ans)) return true;
                    vis[xx][yy] = false;
                }
            }
        }
        
        return false;
    }
    int n,m;
    const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    bool vis[1024][1024];
    Trie trie;
};

