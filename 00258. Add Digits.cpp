/**
 Status: Accepted
 Runtime: 8 ms
 Submitted: 1 year, 6 months ago
*/
class Solution {
public:
    int addDigits(int num) {
        char str[105];
        sprintf(str, "%d",num);
        
        int len = (int)strlen(str);
        int ans = num;
        while (len > 1) {
            ans = 0;
            for(int i=0;i<len;i++){
                ans+=(str[i]-'0');
            }
            
            sprintf(str, "%d",ans);
            len = (int)strlen(str);
        }
        
        return ans;
    }
    
};
