class Solution {
public:
    int minimumLengthEncoding(vector<string>& w) {
        unordered_set<string> st(w.begin(), w.end());
        
        
        for(auto && str : w)
            for(auto i=1;i<str.length();++i)
                st.erase(str.substr(i));
        int ans = 0;
        
        for(auto&& str : st) ans+=str.length() + 1;
        
        return ans;
    }
};
