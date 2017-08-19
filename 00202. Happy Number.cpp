/**
 Status: Accepted
 Runtime: 8 ms
 Submitted: 1 year, 10 months ago
*/

class Solution {
public:
    Solution(){
        hashSet = new set<int>();
        str = new char[1024];
    }
    
    ~Solution(){
        delete []str;
        delete hashSet;
    }
    
    bool isHappy(int n) {
        while(n!=1){
            hashSet->insert(n);
            memset(str, '\0', sizeof(char)*1024);
            sprintf(str, "%d",n);
            int len = (int)strlen(str);
            int sum = 0;
            for(int i=0;i<len;i++){
                int bitNum = (str[i] - '0');
                sum += (bitNum * bitNum);
            }
            n = sum;
            if(hashSet->find(n) != hashSet->end()){
                return false;
            }
        }
        return true;
    }
private:
    set<int> *hashSet;
    char *str;
};
