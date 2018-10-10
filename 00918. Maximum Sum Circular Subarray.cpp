//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;



/**
 
 918. Maximum Sum Circular Subarray
 
 Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
 
 Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
 
 Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)
 
 
 
 Example 1:
 
 Input: [1,-2,3,-2]
 Output: 3
 Explanation: Subarray [3] has maximum sum 3
 Example 2:
 
 Input: [5,-3,5]
 Output: 10
 Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
 Example 3:
 
 Input: [3,-1,2,-1]
 Output: 4
 Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
 Example 4:
 
 Input: [3,-2,2,-3]
 Output: 3
 Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
 Example 5:
 
 Input: [-2,-3,-1]
 Output: -1
 Explanation: Subarray [-1] has maximum sum -1
 
 
 Note:
 
 -30000 <= A[i] <= 30000
 1 <= A.length <= 30000
 
 
 */

/**
 
 108 / 108 test cases passed.
 Status: Accepted
 Runtime: 160 ms
 
 */

// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans = 0;
        int sum = A.back();
        vector<int> nums = A;
        int lowCnt = 0, lowwer = 0;
        // 一个骗答案的剪枝， 如果负数个数小于等于1的话，那么连续子序列的和是数组和减去该负数
        if(A.back() < 0){
            lowCnt++;
            lowwer = A.back();
        }
        
        for(auto i=0;i<A.size() - 1; ++i){
            nums.push_back(A[i]);
            sum+=A[i];
            
            if(A[i] < 0){
                lowCnt++;
                lowwer = A[i];
            }
        }
        
        if(lowCnt <= 1){
            return sum - lowwer;
        }
        
        
        // 常规遍历，遇到子序列个数最大时，回退回之前开始的下一个下标
        vector<int> dp(nums.size(), 0);
        ans = dp[0] = nums[0];
        int cnt = 1;
        for(auto i=1; i<nums.size(); ++i){
            if(dp[i-1] + nums[i] > nums[i]){
                ++cnt;
                dp[i] = dp[i-1] + nums[i];
                if(cnt == A.size()){
                    ans = max(dp[i], ans);
                    i = i+1 - cnt;// roll back
                    dp[i] = 0;
                }
            } else {
                cnt = 1;
                dp[i] = nums[i];
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<int> nums = {-2,-3,-1};
    cout<<solve.maxSubarraySumCircular(nums)<<endl;
    return 0;
}

