/**
 Status: Accepted
 Runtime: 104 ms
 Submitted: 1 year, 6 months ago
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> table;
        
        for(int i=0;i<(int)nums.size();i++){
            if(table[nums[i]]) return true;
            table[nums[i]] = 1;
        }
        
        return false;
    }
    
};
