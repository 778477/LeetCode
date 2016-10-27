
//	Accepted	28 ms	cpp
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;

        vector<int> left(prices.size(),0);
        vector<int> right(prices.size(),0);

        int n = prices.size();
        int tmpmin = prices[0];
        for(int i = 1;i < n;i++)
        {
            tmpmin = min(tmpmin,prices[i]);
            left[i] = max(left[i-1],prices[i]-tmpmin);
        }

        int tmpmax = prices[n-1];
        for(int i = n-2;i >= 0;i--)
        {
            tmpmax = max(tmpmax,prices[i]);
            right[i] = max(right[i+1],tmpmax-prices[i]);
        }

        int ans = 0;
        
        for(int i = 0;i<n;i++)
            ans = max(ans,left[i]+right[i]);
            
        return ans;
    }

};
