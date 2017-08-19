/**
 Status: Accepted
 Runtime: 8 ms
 Submitted: 1 year, 3 months ago
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        
        while(!(n%4)) n/=4;
        
        return n == 1;
    }
};
