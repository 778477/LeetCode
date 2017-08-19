/**
 Status: Accepted
 Runtime: 596 ms
 Submitted: 1 year, 6 months ago
*/

typedef struct NumArray {
    int sumValue;
    int value;
} NumArray;

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
    NumArray* arr = (NumArray*)malloc(sizeof(NumArray)*(numsSize + 5));
    memset(arr, 0, sizeof(NumArray)*(numsSize + 5));
    for(int i =1;i<=numsSize;i++){
        arr[i].sumValue = arr[i-1].sumValue + nums[i-1];
        arr[i].value = nums[i-1];
    }
    return arr;
}

int sumRange(struct NumArray* numArray, int i, int j) {
    if(i > j) return 0;
    
    return numArray[j+1].sumValue - numArray[i+1].sumValue + numArray[i+1].value;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
    free(numArray);
}
