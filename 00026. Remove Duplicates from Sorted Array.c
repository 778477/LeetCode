
//Accepted    17 ms    c
int removeDuplicates(int A[], int n) {
   int *B = (int*)malloc(n*sizeof(int));
   int start = 0;
   for(int i=0;i<n;i++){
       if(start < 1 || B[start-1] != A[i]){
           B[start++] = A[i];
       }
   }
   memcpy(A, B, n*sizeof(int));
   return start; 
}


