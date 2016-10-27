
//Accepted	28 ms	cpp
class Solution {
public:
    int gcd(int a,int b)
    {
        return (b>0)?gcd(b,a%b):a;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        n = rowIndex;
        int limit = (rowIndex+2)>>1,tmp,tmp1,tmp2;
        ans[0] = 1;
        tmp = tmp1 = tmp2 = 1;
        for(int i = 1;i<limit;i++)
        {
            n = ans[i] = n/(i/(tmp2));
            tmp = gcd(n,i+1);
            tmp1 = gcd(rowIndex-i,i+1);
//            n = (n/tmp) * ((rowIndex-i)/tmp1);
            if(tmp > tmp1) n = (n/tmp)*(rowIndex-i),tmp2 = tmp;
            else n = n*(rowIndex-i)/tmp1,tmp2 = tmp1;
//            printf("%I64d %d %d %d\n",n,tmp,tmp1,ans[i]);
        }
        for(int i = limit,j=(rowIndex&1?limit-1:limit-2);i<rowIndex+1;i++,j--)
        {
            ans[i] = ans[j];
        }
        return ans;
    }
private:
    int n;
};
