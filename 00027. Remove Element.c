
//Accepted    2 ms    c
int removeElement(int A[], int n, int elem) {
    int *B = (int *)malloc(sizeof(int) * n);
    memset(B,n,n*sizeof(int));
    int len = 0;
    for(int i=0;i<n;i++){
        if(A[i] != elem)
            B[len++] = A[i];
    }
    memcpy(A,B,n*sizeof(int));
    return len;
}

