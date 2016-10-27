
//	Accepted	12 ms	cpp
class Solution {
public:
    Solution()
    {
        _red = _white = _blue = 0;
    }
    void sortColors(int A[], int n) {
        for(int i=0;i<n;i++){
            if(A[i] == 0) _red++;
            if(A[i] == 1) _white++;
            if(A[i] == 2) _blue++;
        }
        int j = 0,k = 0,total = _red;
        for(int i=k;i<_red;i++){
            A[j++] = 0;
        }
        k = j, total += _white;
        for(int i = k;i<total;i++){
            A[j++] = 1;
        }
        k = j, total += _blue;
        for(int i = k;i<total;i++){
            A[j++] = 2;
        }
    }
private:
    int _red,_white,_blue;
};
