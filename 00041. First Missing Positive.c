
//Accepted	2 ms	c
void myswap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void output(int *nums,int n){
    for(int i=0;i<n;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}
int firstMissingPositive(int* nums, int numsSize) {
//    output(nums,numsSize);
//    int cnt = numsSize - 1;
    for(int i=0;i<numsSize;i++){
        while(nums[i]>0 && nums[i]<=numsSize && nums[nums[i]-1] != nums[i]){
            myswap(&(nums[nums[i]-1]), &(nums[i]));
        }
//        output(nums, numsSize);
    }
//    output(nums,numsSize);
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] != i+1) return i+1;
    }
    return numsSize+1;
}

