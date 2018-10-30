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

#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;



/**
 https://leetcode.com/problems/binary-subarrays-with-sum/
 
 In an array A of 0s and 1s, how many non-empty subarrays have sum S?
 
 
 
 Example 1:
 
 Input: A = [1,0,1,0,1], S = 2
 Output: 4
 Explanation:
 The 4 subarrays are bolded below:
 [1,0,1,0,1]
 [1,0,1,0,1]
 [1,0,1,0,1]
 [1,0,1,0,1]
 
 
 Note:
 
 A.length <= 30000
 0 <= S <= A.length
 A[i] is either 0 or 1.
 
 */

/**
 
 
 59 / 59 test cases passed.
 Status: Accepted
 Runtime: 1320 ms
 
 */



// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
    public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0;
        int sum = 0;
        sum = accumulate(A.begin(), A.end(), 0);
        
        if(sum < S){
            return 0;
        }
        
        for(int star = 0; star < (int)A.size(); ++star){
            
            int length = 1;
            int tmpSum = A[star];
            
            while(star + length < (int)A.size() && tmpSum + A[star + length] <= S){
                tmpSum += A[star + length];
                ++length;
            }
            --length;
            while(tmpSum == S && length >= 0){
                ++ans;
                tmpSum -= A[star + length];
                --length;
            }
            
            
            sum -= A[star];
            if(sum < S) break;
        }
        return ans;
    }
};



int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<int> nums = {0,0,0,0,0};
    cout<<solve.numSubarraysWithSum(nums, 0)<<endl;
    
    return 0;
}

