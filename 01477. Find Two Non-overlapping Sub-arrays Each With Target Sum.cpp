/**
1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

You have to find two non-overlapping sub-arrays of arr each with sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

 

Example 1:

Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
Example 2:

Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.
Example 3:

Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.
Example 4:

Input: arr = [5,5,4,4,5], target = 3
Output: -1
Explanation: We cannot find a sub-array of sum = 3.
Example 5:

Input: arr = [3,1,1,1,5,1,2,1], target = 3
Output: 3
Explanation: Note that sub-arrays [1,2] and [2,1] cannot be an answer because they overlap.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 1000
1 <= target <= 10^8
*/


// Test Cases
// [3,2,2,4,3]
// 3
// [7,3,4,7]
// 7
// [4,3,2,6,2,3,4]
// 6
// [5,5,4,4,5]
// 3
// [3,1,1,1,5,1,2,1]
// 3
// [31,1,1,18,15,3,15,14]
// 33
// [1,6,1]
// 7
// [47,17,4,8,8,2,1,1,8,35,30,1,11,1,1,1,44,1,3,27,2,8]
// 88 

// 57 / 57 test cases passed.
// Status: Accepted
// Runtime: 600 ms
// Memory Usage: 118.2 MB

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        vector<int> dp(arr.size(), arr.size() + 1);
        int ans = arr.size() + 1;
        for (int i = 0; i<arr.size(); i++) {
            sum += arr[i];
            if (mp.find(sum - target) != mp.end()) {
                int preIdx = mp[sum-target];
                dp[i] = i - preIdx;
                if (preIdx != -1) {
                    ans = min(ans, dp[preIdx] + dp[i]);
                }
            }
            mp[sum] = i;
            if (i > 0) dp[i] = min(dp[i], dp[i-1]);
        }
        
        
        return ans == arr.size() + 1 ? -1 : ans;
    }
};

