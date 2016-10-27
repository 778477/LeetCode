
//Accepted	44 ms	cpp
class Solution {
public:
    double pow(double x, int n) {
        if(n >= 0) return myPow(x,n);
        else return 1/myPow(x,-n);
    }

    double myPow(double x,int n)
    {
        if(n == 0) return 1;
        if(n == 1) return x;
        double tmp = myPow(x,n/2);
        if(n&1) return tmp*tmp*x;
        return tmp*tmp;
    }
};

