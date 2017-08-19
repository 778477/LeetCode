/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 2 years, 2 months ago
*/
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void output(int *nums,int p,int q){
    for(int i=p;i<q;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int RandSelectElement(int *nums,int p,int q){
    int randomIdx = rand()%(q-p)+p;
    swap(&nums[p],&nums[randomIdx]);
    int val = nums[p];
    int ansIdx = p+1;
    for(int i=p+1;i<q;i++){
        if(nums[i] < val){
            swap(&nums[i], &nums[ansIdx]);
            ansIdx++;
        }
    }
    nums[p] = nums[ansIdx-1];
    nums[ansIdx-1] = val;
    return ansIdx-1;
}

int findKthElement(int *nums, int startIndex,int endIndex, int k){
    if(startIndex == endIndex) return nums[k];
    int idx = RandSelectElement(nums, startIndex, endIndex);
    int kk = idx - startIndex + 1;
    if(kk < k){
        return findKthElement(nums, idx+1, endIndex,k-kk);
    }
    else if (kk > k){
        return findKthElement(nums, startIndex, idx,k);
    }
    return nums[idx];
}

int findKthLargest(int* nums, int numsSize, int k) {
    return findKthElement(nums,0,numsSize,numsSize-k+1);
}
