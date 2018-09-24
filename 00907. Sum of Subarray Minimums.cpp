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
 
 907. Sum of Subarray Minimums
 DescriptionHintsSubmissionsDiscussSolution
 Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.
 
 Since the answer may be large, return the answer modulo 10^9 + 7.
 
 
 
 Example 1:
 
 Input: [3,1,2,4]
 Output: 17
 Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
 Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 
 
 Note:
 
 1 <= A.length <= 30000
 1 <= A[i] <= 30000
 
 
 */

/**
 
 
 92 / 100 test cases passed.
 Status: Time Limit Exceeded
 
 
 O(n) 一次遍历中使用count记录最小值的变化，优化计算栈中元素不超时
 超时反例：https://leetcode.com/submissions/detail/178144461/
 
 100 / 100 test cases passed.
 Status: Accepted
 Runtime: 64 ms
 
 */

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0;
        const int MOD = 1e9+7;
        typedef pair<int, int> pp; // val : cnt
        stack<pp> s;
        int preStackSum = 0;
        
        for(auto i=0;i<A.size();++i){
            int cnt = 1;
            while (!s.empty() && s.top().first > A[i]) {
                cnt += s.top().second;
                preStackSum -= s.top().first * s.top().second;
                s.pop();
            }
            s.push(make_pair(A[i], cnt));
            preStackSum += A[i]*cnt;
            ans += preStackSum;
            ans %= MOD;
        }
        return ans;
    }
};

/**
 case 1:
 [48,87,27]
 
 */

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    Solution solve;
    vector<int> nums = {48,87,27};
    cout<<solve.sumSubarrayMins(nums)<<endl;
    return 0;
}

