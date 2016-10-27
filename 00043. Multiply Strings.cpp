
//Accepted	122 ms	cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        num1 = clearPreZero(num1);
        num2 = clearPreZero(num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "0",tmpAns;
        size_t len = max(num1.length(), num2.length());
        size_t carrayBit,tmp;
        for(size_t i = 0; i < len; i++){
            size_t a = getCharAtIndex(num1, i);
            if(!a) continue;
            tmpAns.clear();
            carrayBit = tmp = 0;
            for(size_t j = 0; j < num2.length(); j++){
                tmp = getCharAtIndex(num2, j)*a + carrayBit;
                carrayBit = tmp/10;
                tmpAns.push_back((tmp%10)+'0');
            }
            if(carrayBit) tmpAns.push_back(carrayBit + '0');
            reverse(tmpAns.begin(), tmpAns.end());
            for(size_t j = 0; j < i; j++) tmpAns.push_back('0');
            ans = add(ans , tmpAns);
        }
        return ans;
    }
    
    string add(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        size_t len = max(num1.length(), num2.length());
        string ans;
        ans.clear();
        size_t carryBit = 0, tmp;
        for(size_t i = 0; i < len;i++){
            tmp = getCharAtIndex(num1, i) + getCharAtIndex(num2, i) + carryBit;
            carryBit = tmp / 10 ;
            ans.push_back((tmp % 10)+'0');
        }
        ans.push_back(carryBit+'0');
        reverse(ans.begin(), ans.end());
        return clearPreZero(ans);
    }
    
    string clearPreZero(string num){
        size_t idx = 0;
        while(num[idx] == '0' && idx+1 < num.length()) idx++;
        return num.substr(idx,num.length() - idx);
    }
    
    size_t getCharAtIndex(string num, size_t idx){
        if(idx < num.length()) return num[idx] - '0';
        
        return 0;
    }
};

