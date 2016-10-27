
//	Accepted	16 ms	cpp
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        if(t.length() > s.length()) return ans;
        
        vector<int> countTable(256,0);
        
        for_each(t.begin(), t.end(), [&](const char ch){
            countTable[ch]++;
        });
        
        vector<int> foundTable(256,0);
        int count(0),pos(0);
        unsigned long maxLen(s.length());
        for(size_t i = 0;i<s.length();i++){
            if(countTable[s[i]] > 0){
                foundTable[s[i]] ++;
                if(foundTable[s[i]] <= countTable[s[i]]) count++;
                if(count == t.length()){
                    for(int j=pos;j<=i;j++){
                        if(countTable[s[j]] > 0){
                            foundTable[s[j]] --;
                            if(foundTable[s[j]] < countTable[s[j]]){
                                pos = j;
                                break;
                            }
                        }
                    }
//                    cout<<pos<<" "<<i<<" ";
                    if(i-pos < maxLen) ans = s.substr(pos,i-pos+1),maxLen = ans.length();
//                    cout<<ans<<endl;
                    pos ++;
                    count --;
                }
            }
        }
        return ans;
    }
};
