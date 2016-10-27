
//Accepted	15 ms	cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end(), less<int>() );
    }
    
};

