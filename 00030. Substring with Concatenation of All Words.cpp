
//Accepted	611 ms	cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty() || s.length() < words.size() * words.front().length()) return ans;
        size_t wordLen = words.front().length();
        map<string, int> dict;
        for_each(words.begin(), words.end(), [&](const string tmp){
            dict[tmp]++;
        });
        for(size_t i = 0;i<=s.length() - wordLen*words.size();i++){
            size_t j = 0;
            map<string, int> tmpDict;
            for(j = 0;j<words.size();j++){
                string subStr = s.substr(i+j*wordLen,wordLen);
                if(tmpDict[subStr] < dict[subStr]){
                    tmpDict[subStr]++;
                }
                else{
                    break;
                }
            }
            if(j == words.size()){
                ans.push_back((int)i);
            }
        }
        return ans;
    }
};
