
//Accepted	2 ms	cpp
char mp[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int mpIndex[10] = {0,0,3,3,3,3,3,4,3,4};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        size_t m = digits.length();
        if(m == 0) return ans;
        queue<string> Q;
        Q.push("");
        for(int i=0;i<m;i++){
            size_t n = digits[i] - '0';
            size_t len = Q.size();
            while (len--) {
                string tmp = Q.front();
                Q.pop();
                for(int j=0;j<mpIndex[n];j++){
                    string newStr = tmp + mp[n][j];
                    Q.push(newStr);
                }
            }
        }
        while (!Q.empty()) {
            ans.push_back(Q.front());
            Q.pop();
        }
        return ans;
    }
};



