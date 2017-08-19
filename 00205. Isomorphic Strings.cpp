/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year, 3 months ago
*/

const int CHARMAX = 256;
bool isIsomorphic(char* s, char* t) {
    int len = (int)strlen(s);
    int _aaa[CHARMAX],_bbb[CHARMAX];
    memset(_aaa, 0, sizeof(int)*CHARMAX);
    memset(_bbb, 0, sizeof(int)*CHARMAX);
    for(int i=0;i<len;i++){
        if(_aaa[s[i]] != _bbb[t[i]]) return false;
        _aaa[s[i]] = i+1;
        _bbb[t[i]] = i+1;
    }
    return true;
}
