/**
 Status: Accepted
 Runtime: 20 ms
 Submitted: 1 year, 3 months ago
*/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = (int)s.length()-1;
        char tmp;
        while(i < j){
            if(isVowels(s[i]) && isVowels(s[j])){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                i++,j--;
            }
            
            if(!isVowels(s[i])) i++;
            if(!isVowels(s[j])) j--;
        }
        
        return s;
    }
    
    bool isVowels(const char c){
        for(int i=0;i<10;i++){
            if(c == vowels[i]) return true;
        }
        return false;
    }
private:
    const char *vowels="aeiouAEIOU";
};
