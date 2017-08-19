/**
 Status: Accepted
 Runtime: 4 ms
 Submitted: 1 year, 3 months ago
*/
const int CHARMAX = 10;
char* getHint(char* secret, char* guess) {
    int _aaa[CHARMAX],_bbb[CHARMAX];
    memset(_aaa, 0, sizeof(int)*CHARMAX);
    memset(_bbb, 0, sizeof(int)*CHARMAX);
    
    int bulls = 0;
    int cows = 0;
    
    int len = (int)strlen(secret);
    for(int i=0;i<len;i++){
        if(secret[i] == guess[i]) bulls++;
        _aaa[secret[i]-'0']++;
        _bbb[guess[i]-'0']++;
    }
    
    for(int i=0;i<10;i++){
        if(_aaa[i] && _bbb[i]){
            cows+=(_aaa[i] < _bbb[i] ? _aaa[i] : _bbb[i]);
        }
    }
    char *ans = (char *)malloc(sizeof(char)*256);
    sprintf(ans, "%dA%dB",bulls,cows-bulls);
    
    return ans;
}
