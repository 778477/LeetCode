/**
 Status: Accepted
 Runtime: 8 ms
 Submitted: 1 year, 3 months ago
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        int cnt=0;
        while(n){
            if(n&0x01) cnt++;
            n>>=1;
        }
        return cnt==1;
    }
};
