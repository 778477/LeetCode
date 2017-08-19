/**
 Status: Accepted
 Runtime: 12 ms
 Submitted: 1 year, 3 months ago
*/
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};
