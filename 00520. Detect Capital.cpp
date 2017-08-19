/**
 Status: Accepted
 Runtime: 9 ms
 Submitted: 5 months, 2 weeks ago
*/
bool detectCapitalUse(char* word) {
    int len = strlen(word);
    bool isCap = true;
    bool isSam = true;
    for(int i=0;i<len;i++){
        if(word[i]>='a' && word[i] <= 'z'){
            isCap = false;
        }
    }
    if(isCap) return true;
    
    for(int i=1;i<len;i++){
        if(word[i]>='A' && word[i]<='Z'){
            isSam = false;
        }
    }
    
    if(isSam) return true;
    
    
    return false;
}
