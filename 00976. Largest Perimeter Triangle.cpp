// a + b > c
// max(a+b+c)
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        
        
        for(int i = A.size()-1; i>1; i-=1){
            if(A[i-2] + A[i-1] > A[i]) return A[i-2]+A[i-1]+A[i];
        }
        
        return 0;
    }
};
