/**
 Status: Accepted
 Runtime: 12 ms
 Submitted: 1 year, 5 months ago
*/
int missingNumber(int* nums, int numsSize) {
    int sum = (numsSize - 1)*numsSize/2;
    int total = 0;
    for(int i=0;i<numsSize;i++){
        total += nums[i];
    }
    
    if(total == sum){
        return numsSize;
    }
    else{
        return (sum + numsSize - total);
    }
    
}
