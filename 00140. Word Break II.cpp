
//Accepted	76 ms	cpp
class Solution {
private:
    unordered_set<string> _dict;
    vector<bool> _match;
    vector<string> _ans;
    int _len;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        _dict = dict;
        _match = vector<bool>(s.length()+1,false);
        _ans = vector<string>();
        _len = (int)s.length();
        _match[0] = true;
        for(int i=0;i<_len;i++)
        {
            if(_match[i])
            {
                for(int j=1;j+i < _len+1;j++)
                {
                    if(_dict.find(s.substr(i,j)) != _dict.end())
                        _match[i+j] = true;
                }
            }
        }
        if(_match[s.length()])
            matchTheWord(s, 0,"");
        return _ans;

    }
    
    void matchTheWord(string& s,int index,string str)
    {
        for(int i=1;index + i<s.length()+1;i++)
        {
            if(_match[i+index] && (_dict.find(s.substr(index,i)))!=_dict.end())
            {
                string sub = s.substr(index,i);
                if(index+i < s.length())
                    matchTheWord(s, index+i, str+sub+" ");
                else
                {
                    _ans.push_back(str + sub);
                    return;
                }
                
            }
        }
    }
};
