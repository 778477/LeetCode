/*
 
 96. Unique Binary Search Trees
 Total Accepted: 102874
 Total Submissions: 260772
 Difficulty: Medium
 Contributors: Admin
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3
 Subscribe to see which companies asked this question */


/*
 
 19 / 19 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 Submitted: 0 minutes ago
 
 
 1. 枚举 根节点 1...n
 2. 该根节点下的 左子树个数 * 右子树个数
 */



class Solution {
public:
    int numTrees(int n) {
        int ans = 0;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
        
        memset(dp,0,sizeof(int) * (n+1));
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            for( int root = 1; root <= i ; root++){
                dp[i] = dp[i] + (dp[root-1] * dp[i-root]);
            }
        }
        
        ans = dp[n];
        free(dp);
        return ans ;
    }
};


int main(){
    Solution solve;
    
    for(int i=1;i<20;i++){
        printf("%d = %d\n",i,solve.numTrees(i));
    }
    
    return 0;
}
