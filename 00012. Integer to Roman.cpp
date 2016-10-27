//Accepted	57 ms	cpp
const char RomanNumbers[] = "IVXLCDM";
class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        char tmp[1024]={'\0'};
        sprintf(tmp,"%d",num);
        int len = (int)strlen(tmp);
        for(int i=0;i<len;i++){
            ans.append(numberToRoman(tmp[i]-'0', len-i));
        }
        return ans;
    }
    
    string numberToRoman(int n, int m){
        string str = "";
        if(n != 0){
            int index = (m-1)*2;
            if(n <= 3){
                for(int i=0;i<n;i++){
                    str+=RomanNumbers[index];
                }
            }
            else if(n == 4){
                str+=RomanNumbers[index];
                str+=RomanNumbers[index+1];
            }
            else if(n < 9){
                str+=RomanNumbers[index+1];
                for(int i=n-5;i>0;i--){
                    str+=RomanNumbers[index];
                }
            }
            else{
                str+=RomanNumbers[index];
                str+=RomanNumbers[index+2];
            }
        }
        return  str;
    }
};


