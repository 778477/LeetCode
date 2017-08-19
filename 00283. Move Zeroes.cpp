/**
 Status: Accepted
 Runtime: 124 ms
 Submitted: 1 year, 6 months ago
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int)nums.size();
        int cnt = 0;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                idx = i;
                for(int j=i+1;j<n-cnt;j++){
                    if(nums[j] != 0){
                        swap(nums[idx],nums[j]);
                        idx = j;
                    }
                }
                cnt++;
            }
        }
    }
};
