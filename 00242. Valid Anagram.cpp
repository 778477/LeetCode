/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year, 10 months ago
*/
bool isAnagram(char* s, char* t) {
    int *chars = (int *)malloc(sizeof(int)*27);
    int slen = strlen(s),tlen = strlen(t),i,sum;
    memset(chars,0,sizeof(int)*27);
    for(i=0;i<slen;i++){
        chars[s[i]-'a']++;
    }
    
    for(i=0;i<tlen;i++){
        chars[t[i]-'a']--;
    }
    
    
    for(int i=0;i<27;i++){
        if(chars[i]) return false;
    }
    
    return true;
}
