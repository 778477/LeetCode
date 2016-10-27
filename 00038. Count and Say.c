
//Accepted	0 ms	c
#define N 40960
char* countAndSay(int n) {
    char *ans = (char*)malloc(N);
    memset(ans,'\0',N);
    ans[0] = '1';
    if(n == 1) return ans;
    
    for(int i=2;i<=n;i++){
        char num = ans[0];
        int cnt = 1;
        int len = (int)strlen(ans);
        char *tmp = (char*)malloc(N);
        memset(tmp, '\0', N);
        int tmpidx = 0;
        for(int j=1;j<len;j++){
            if(ans[j] == num){
                cnt ++;
            }
            else{
                tmp[tmpidx] = cnt + '0';
                tmp[tmpidx+1] = num;
                num = ans[j];
                cnt = 1;
                tmpidx+=2;
            }
        }
        tmp[tmpidx] = cnt+'0';
        tmp[tmpidx+1] = num;
        memcpy(ans, tmp, N);
        free(tmp);
    }
    
    return ans;
}
