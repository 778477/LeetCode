class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> cnt;
        int ans = 0, sum = 0;
        cnt[0] = 1;
        for(int a:A){
            sum = (sum + a) % K;
            if(sum < 0) sum += K;
            ans += cnt[sum];
            ++cnt[sum];
        }
        
        return ans;
    }
};
