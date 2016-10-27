
//Accepted	0 ms	c
int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = 0,j=len-1;
    int ans = 0;
    while(i < len && s[i] == ' ') i++;
    while(j > -1  && s[j] == ' ') j--;
    if(j < i) return 0;
    while(j>=i && s[j]!=' ') j--,ans++;
    
    return ans;
}

