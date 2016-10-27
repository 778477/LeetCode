class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int tot = m + n;
        if(tot & 0x1)
            return findKthNum(A, m, B, n, tot/2+1);
        else
            return (findKthNum(A, m, B, n, tot/2) + findKthNum(A, m, B, n, tot/2 + 1))*1.0 / 2;
    }
    
    int findKthNum(int a[],int m, int b[], int n, int k){
        if(m > n) return findKthNum(b, n, a, m, k);
        if(m == 0) return b[k-1];
        if(k == 1) return min(a[0],b[0]);
        
        int pa = min(k/2,m), pb = k - pa;
        if(a[pa - 1] < b[pb-1]){
            return findKthNum(a+pa, m-pa, b, n, k-pa);
        }
        else if(a[pa - 1] > b[pb-1]){
            return findKthNum(a, m, b+pb, n-pb, k-pb);
        }
        return a[pa-1];
    }
};

