
//Accepted	0 ms	c
int search(int* nums, int numsSize, int target) {
    int i=0;
    for(i =0;i<numsSize;i++){
        if(target == nums[i]) return i;
    }
    return -1;
}
