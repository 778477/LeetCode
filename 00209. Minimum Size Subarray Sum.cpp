/**
 Status: Accepted
 Runtime: 4 ms
 Submitted: 1 year, 4 months ago
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        size_t n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        int p = 0,q = 0;
        
        while(q < n){
            sum += nums[q++];
            
            while(sum >= s){
                ans = min(ans,q-p);
                sum -= nums[p++];
            }
            
        }
        
        return ans==INT_MAX ? 0 : ans;
    }
};
