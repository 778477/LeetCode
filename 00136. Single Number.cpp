
//Accepted	20 ms	cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = 0;
        
        for_each(nums.begin(), nums.end(), [&](const int num){
            tmp = tmp^num;
        });
        
        return tmp;
    }
};
