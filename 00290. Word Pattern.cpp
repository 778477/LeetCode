/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year, 3 months ago
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> v = spilt(str, " ");
        if(pattern.size() != v.size()) return false;
        map<string,int> m;
        int mark[256] = {0};
        
        for(int i=0;i<pattern.length();i++){
            if(mark[pattern[i]] != m[v[i]]){
                return false;
            }
            mark[pattern[i]] = i+1;
            m[v[i]] = i+1;
        }
        
        return true;
    }
    
private:
    vector<string> spilt(const string& s,const string& delim){
        vector<string> v;
        
        size_t last = 0;
        size_t index=s.find_first_of(delim,last);
        if(index == string::npos){
            v.push_back(s);
            return v;
        }
        while (index!=std::string::npos)
        {
            v.push_back(s.substr(last,index-last));
            last=index+1;
            index=s.find_first_of(delim,last);
        }
        if (index-last>0)
        {
            v.push_back(s.substr(last,index-last));
        }
        
        return v;
    }
};
