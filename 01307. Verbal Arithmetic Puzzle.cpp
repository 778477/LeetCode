#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 
 1307. Verbal Arithmetic Puzzle
 
 Given an equation, represented by words on left side and the result on right side.
 
 You need to check if the equation is solvable under the following rules:
 
 Each character is decoded as one digit (0 - 9).
 Every pair of different characters they must map to different digits.
 Each words[i] and result are decoded as one number without leading zeros.
 Sum of numbers on left side (words) will equal to the number on right side (result).
 Return True if the equation is solvable otherwise return False.
 
 
 
 Example 1:
 
 Input: words = ["SEND","MORE"], result = "MONEY"
 Output: true
 Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
 Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
 Example 2:
 
 Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
 Output: true
 Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
 Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
 Example 3:
 
 Input: words = ["THIS","IS","TOO"], result = "FUNNY"
 Output: true
 Example 4:
 
 Input: words = ["LEET","CODE"], result = "POINT"
 Output: false
 
 
 Constraints:
 
 2 <= words.length <= 5
 1 <= words[i].length, result.length <= 7
 words[i], result contains only upper case English letters.
 Number of different characters used on the expression is at most 10.
 */

// 28 / 28 test cases passed.
// Status: Accepted
// Runtime: 52 ms
// Memory Usage: 8.2 MB
class Solution {
private:
    vector<int> _mapping;
    vector<bool> _vis;
public:
    void output(vector<string>& words, string& result){
        for(int i = 0; i<words.size(); i++) {
            reverse(words[i].begin(), words[i].end());
            for(int j = 0; j<words[i].length(); ++j){
                cout<<_mapping[words[i][j] - 'A'];
            }
            if(i + 1 != words.size()) cout<<" + ";
        }
        reverse(result.begin(), result.end());
        cout<<" = ";
        for(int i = 0; i<result.length(); i++) cout<<_mapping[result[i] - 'A'];
        cout<<endl;
    }
    bool dfs(vector<string>& words, string& result, int idx, int jdx, int digit) {
        if(idx >= words.size() && jdx >= result.length()) {
            if(digit == 0){
                output(words, result);
            }
            return digit == 0;
        }
        
        if(idx >= words.size()) {
            if(_mapping[result[jdx] - 'A'] != -1) {
                if(_mapping[result[jdx] - 'A'] != digit%10)
                    return false;
                return dfs(words, result, 0, jdx+1, digit/10);
            } else {
                if(_vis[digit%10]) return false;
                if(jdx + 1 == result.length() && digit == 0) return false;
                
                _mapping[result[jdx] - 'A'] = digit%10;
                _vis[digit%10] = true;
                if(dfs(words, result, 0, jdx+1, digit/10)){
                    return true;
                }
                _mapping[result[jdx] - 'A'] = -1;
                _vis[digit%10] = false;
                return false;
            }
        }
        
        if(jdx >= words[idx].length()) {
            return dfs(words, result, idx + 1, jdx, digit);
        }
        
        if(_mapping[words[idx][jdx] - 'A'] != -1) {
            return dfs(words, result, idx + 1, jdx, digit + _mapping[words[idx][jdx] - 'A']);
        }
        
        for(int i = 0; i < 10; ++i) {
            if(_vis[i]) continue;
            if(i == 0 && words[idx][jdx] == words[idx].back()) continue;
            
            _vis[i] = true;
            _mapping[words[idx][jdx] - 'A'] = i;
            if(dfs(words, result, idx + 1, jdx, digit + i)) {
                return true;
            }
            _vis[i] = false;
            _mapping[words[idx][jdx] - 'A'] = -1;
        }
        
        return false;
    }
    
    bool isSolvable(vector<string>& words, string result) {
        for(auto i = 0; i < words.size(); ++i) {
            if(words[i].length() > result.length()) {
                return false;
            }
            reverse(words[i].begin(), words[i].end());
        }
        
        reverse(result.begin(), result.end());
        _mapping = vector<int>(26, -1);
        _vis     = vector<bool>(10, false);
        return dfs(words, result, 0, 0, 0);
    }
};

int main(){
    vector<string> words = {"SEND", "MORE"};
    Solution solve;
    cout<<solve.isSolvable(words, "MONEY")<<endl;
    return 0;
}
