/**
 Status: Accepted
 Runtime: 80 ms
 Submitted: 1 year, 6 months ago
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!k) return false;
        int n = (int)nums.size();
        if(k >= n) k = n;
        map<int,int> table;
        
        for(int i=0;i<=k;i++){
            if(table[nums[i]]) return true;
            table[nums[i]] = 1;
        }
        
        for(int i=k+1;i<n;i++){
            table[nums[i-k-1]] = 0;
            
            if(table[nums[i]]) return true;
            table[nums[i]] = 1;
        }
        
        
        return false;
    }
    
};
