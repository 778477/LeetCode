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
 
 565. Array Nesting
 
 A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.
 
 Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.
 
 Example 1:
 Input: A = [5,4,0,3,1,6,2]
 Output: 4
 Explanation:
 A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
 
 One of the longest S[K]:
 S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 Note:
 N is an integer within the range [1, 20,000].
 The elements of A are all distinct.
 Each element of A is an integer within the range [0, N-1].
 
 */

/**
 
 856 / 856 test cases passed.
 Status: Accepted
 Runtime: 20 ms
 
 */

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<bool> visit(nums.size(), false);
        for(auto i=0; i<nums.size(); ++i){
            if(!visit[i]){
                int cnt = 1;
                int next = nums[i];
                visit[i] = true;
                while(!visit[next]){
                    ++cnt;
                    visit[next] = true;
                    next = nums[next];
                }
                ans = max(ans, cnt);
                if(ans > nums.size()/2) return ans;
            }
        }
        return ans;
    }
};



int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<int> nums = {0,2,1};
    cout<<solve.arrayNesting(nums)<<endl;
    return 0;
}

