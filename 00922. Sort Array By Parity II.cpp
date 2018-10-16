
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
 
 922. Sort Array By Parity II
 
 Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
 
 Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
 
 You may return any answer array that satisfies this condition.
 
 
 
 Example 1:
 
 Input: [4,2,5,7]
 Output: [4,5,2,7]
 Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 
 
 Note:
 
 2 <= A.length <= 20000
 A.length % 2 == 0
 0 <= A[i] <= 1000
 
 
 
 */

/**
 
 61 / 61 test cases passed.
 Status: Accepted
 Runtime: 104 ms
 
 */



// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
    public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans = A;
        
        unsigned even = 0, odd = 1;
        
        while(even < ans.size()){
            
            while(even < ans.size() && (ans[even]&0x01) == 0){
                even += 2;
            }
            
            while (odd < ans.size() && (ans[odd]&0x01) == 1) {
                odd += 2;
            }
            
            
            if(even < ans.size()){
                swap(ans[odd], ans[even]);
                even+=2;
                odd+=2;
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<int> nums = {4,2,5,7};
    vector<int> ans = solve.sortArrayByParityII(nums);
    for(int n : ans){
        cout<<n<<" ";
    }
    return 0;
}
