/**
 Status: Accepted
 Runtime: 36 ms
 Submitted: 6 months, 1 week ago
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                ans = count > ans ? count : ans;
                count = 0;
            } else{
                count++;
            }
        }
        
        ans = count > ans ? count : ans;
        return ans;
    }
};
