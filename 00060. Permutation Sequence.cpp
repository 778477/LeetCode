
//Accepted	0 ms	cpp

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string str = "";
        vector<int> numbers;
        vector<int> ans;
        for(int i=1;i<=n;i++) numbers.push_back(i);
        
        if(k == jiecheng(n)){
            for(int i=n;i>0;i--) str+=('0'+i);
            return str;
        }
        
        for(int i=1;i<n;i++){
            int num = jiecheng(n-i);
            int index = (k-1)/num;
            str += ('0' + numbers[index]);
            numbers.erase(numbers.begin() + index);
            k = k-index*num;
        }
        str+= ('0' + numbers[0]);
        return str;
    }
private:
    int jiecheng(int n){
        int ans = n;
        while(--n) ans*=n;
        return ans;
    }
};

