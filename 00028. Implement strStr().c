
//Accepted	4 ms	cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.length();
        int nlen = needle.length();
        
        for(int i=0;i<=hlen-nlen;i++){
            int j = 0;
            for(;j<nlen;j++){
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == nlen) return i;
        }
        
        return -1;
    }
};

