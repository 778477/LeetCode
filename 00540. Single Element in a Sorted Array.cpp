/**
 7 / 7 test cases passed.
 Status: Accepted
 Runtime: 6 ms
 Submitted: 2 weeks, 3 days ago
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int val = 0;
        
        for(int num : nums){
            val = val^num;
        }
        
        return val;
    }
};
