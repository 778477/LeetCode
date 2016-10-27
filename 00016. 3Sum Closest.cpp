
//Accepted	88 ms	cpp
class Solution {
public:
    int Abs(int a)
    {
        return a>0?a:-a;
    }
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int n = num.size()-2;
        int ans = -0x3fff3fff,tmp = 0;
        for(int i=0;i<n;i++)
        {
            int right = i+1;
            int left = num.size()-1;
            while(right < left)
            {
                tmp = num[i] + num[right] + num[left];
                if(Abs(target-tmp) < Abs(ans-target)) ans = tmp;
                if(tmp > target) left--;
                else if(tmp < target) right++;
                else
                    return target;
            }
        }
        return ans;
    }
};


