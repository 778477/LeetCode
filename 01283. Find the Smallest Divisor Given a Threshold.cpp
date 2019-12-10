#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

/**
 * 
 * 
1283. Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division.

Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
Example 3:

Input: nums = [19], threshold = 5
Output: 4
 

Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6
 **/


// 59 / 59 test cases passed.
// Status: Accepted
// Runtime: 44 ms
// Memory Usage: 11.5 MB

class Solution {
public:
    bool valid(int val, vector<int>& nums, int threshold){
        int ret = 0;
        for(int num : nums){
            ret = ret + (num + val - 1) / val;
        }
        return ret <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = 1e6;
        int mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(valid(mid, nums, threshold)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


int main(){
    Solution solve;
    vector<int> nums = {19};
    cout<<solve.smallestDivisor(nums, 5)<<endl;
}