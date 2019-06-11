
[动态规划 - 最长公共子序列专题](https://www.geeksforgeeks.org/tag/lcs/)




## Longest Common Subsequence - LCS

基础原型题：
给定两个数字序列(可以是字符串)。求这两个序列中公共子序列的最长长度是多少？

[longest-common-subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0)


动态规划标准解法：
```C++
int lcs(const string& a, int n, const string& b,int m){
    int dp[n+1][m+1] = {0};
	memset(dp, 0, sizeof(int)*(n+1)*(m+1));
	
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
	        dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (a[i-1]==b[j-1]?1:0));
	    }
	}
	return dp[n][m];
}
```

递归解法： 容易超时
```C++
int lcs(const string& a, int n, const string& b, int m){
    if( n == 0 || m == 0) return 0;
    if( a[n - 1] == b[m - 1]) return 1+lcs(a,n-1,b,m-1);

    return max(lcs(a,n-1,b,m), lcs(a,n,b,m-1));
}
```



### [Edit Distance](https://practice.geeksforgeeks.org/problems/edit-distance/0)

> Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

> 1.Insert

> 2.Remove

> 3.Replace

> All of the above operations are of cost=1.
Both the strings are of lowercase.

```C++
int editDistance(const string& a, int n, const string& b, int m){
    int dp[n+1][m+1] = {0};
	memset(dp, 0, sizeof(int) * (n+1) * (m+1));
	
	for(int i=1;i<=n;i++) dp[i][0] = i;
	for(int i=1;i<=m;i++) dp[0][i] = i;
	
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
	        int c = a[i-1] == b[j-1] ? 0 : 1;
	        
	        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]) + 1, dp[i-1][j-1] + c);
	        
	    }
	}
	return dp[n][m];
}
```
