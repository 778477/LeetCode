
//Accepted	6 ms	c
int maxSubArray(int* nums, int numsSize) {
    int *dp = (int*)malloc(numsSize * sizeof(int));
    dp[0] = nums[0];
    int ans = dp[0];
    for(int i=1;i<numsSize;i++){
        dp[i] = nums[i]+dp[i-1]>nums[i]?nums[i]+dp[i-1]:nums[i];
        if(dp[i] > ans) ans = dp[i];
    }
    free(dp);
    return ans;
}
