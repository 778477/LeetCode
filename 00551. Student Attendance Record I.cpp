/**
 
 113 / 113 test cases passed.
 Status: Accepted
 Runtime: 3 ms
 Submitted: 3 months, 1 week ago
*/

class Solution {
public:
    bool checkRecord(string s) {
        int a,l;
        a = l = 0;
        
        for(char c : s){
            if(c == 'L'){
                ++l;
            } else {
                l = 0;
            }
            
            if(c == 'A') a++;
            
            if(a>1 || l>2) return false;
        }
        
        return true;
    }
};
