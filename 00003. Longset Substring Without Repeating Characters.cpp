int vis[1024];
int lengthOfLongestSubstring(char *s) {
    int len = (int)strlen(s);
    if(len <= 1) return len;
    int ans = 1,i = 0,j=1;
    memset(vis, 0, sizeof(vis));
    vis[s[i]] = 1;
    while (j<len) {
        if(!vis[s[j]]){
            if(j-i+1 > ans) ans = j-i+1;
            vis[s[j]] = 1;
            j++;
        }
        else{
            vis[s[i]] = 0;
            i++;
        }
    }
    return ans;
}

