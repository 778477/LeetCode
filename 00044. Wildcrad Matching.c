
//Accepted	12 ms	c
bool isMatch(char* s, char* p) {
    if(*p == 0) return *s == 0;
    char *star = NULL;
    char *ss = s;
    while(*s){
        if((*p == '?') || (*p == *s)){
            s++,p++;
            continue;
        }
        if(*p == '*'){
            star = p++;
            ss = s;
            continue;
        }
        if(star){
            s = ++ss;
            p = star+1;
            continue;
        }
        return false;
    }
    while(*p == '*') p++;
    return !*p;
}
