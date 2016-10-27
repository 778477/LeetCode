
// 	Accepted	19 ms	c

const char RomanNumbers[] = "IVXLCDM";
int findRomanIndex(const char ch){
    for(int i=0;i<7;i++)
    {
        if(ch == RomanNumbers[i])
            return i;
    }
    return 0;
}
int romanToInt(char *s) {
    int number = 0;
    int len = (int)strlen(s);
    int fir = -1,sec = -1,tmp,index;
    for(int i=0;i<len;i++)
    {
        index = findRomanIndex(s[i]);
        tmp = 1;
        for(int j=0;j<(index+1)/2;j++) tmp *=10;
        
        if(index&1) tmp/=2;
        
        if(fir == -1){
            fir = tmp;
        }
        else if(sec == -1){
            sec = tmp;
            if(fir >= sec){
                number += fir;
                fir = sec;
                sec = -1;
            }
            else{
                number -= fir;
                fir = sec;
                sec = -1;
            }
        }
    }
    number += fir;
    return number;
}


