/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year, 3 months ago
*/

int max(const int a,const int b){
    return a > b ? a : b;
}

int easyRob(int* nums, int numsSize){
    int odd = 0, eve = 0;
    
    for(int i=0;i<numsSize;i++){
        if(i%2) eve += nums[i];
        else odd += nums[i];
    }
    
    return max(odd,eve);
}

int rob(int* nums, int numsSize) {
    if(numsSize <= 3) return easyRob(nums,numsSize);
    
    int *dp = (int *)malloc(sizeof(int)*(numsSize + 5));
    memset(dp, 0, sizeof(int)*(numsSize + 5));
    dp[0] = nums[0];
    dp[1] = max(nums[1],nums[0]);
    dp[2] = max(dp[0]+nums[2],dp[1]);
    
    for(int i=3;i<numsSize;i++){
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    }
    
    int ans = dp[numsSize-1];
    free(dp);
    return ans;
}
