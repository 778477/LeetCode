/**
 Status: Accepted
 Runtime: 124 ms
 Submitted: 1 year, 3 months ago
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        
        while(!(n%3)) n/=3;
        
        return n == 1;
    }
};
