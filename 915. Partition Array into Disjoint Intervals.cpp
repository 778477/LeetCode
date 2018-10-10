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
 
 915. Partition Array into Disjoint Intervals
 
 Given an array A, partition it into two (contiguous) subarrays left and right so that:
 
 Every element in left is less than or equal to every element in right.
 left and right are non-empty.
 left has the smallest possible size.
 Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.
 
 
 
 Example 1:
 
 Input: [5,0,3,8,6]
 Output: 3
 Explanation: left = [5,0,3], right = [8,6]
 Example 2:
 
 Input: [1,1,1,0,6,12]
 Output: 4
 Explanation: left = [1,1,1,0], right = [6,12]
 
 
 Note:
 
 2 <= A.length <= 30000
 0 <= A[i] <= 10^6
 It is guaranteed there is at least one way to partition A as described.
 
 
 */

/**
 
 56 / 56 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
 */

// testcase input io faster
static int x = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int ans = 0;
        
        vector<int> l(A.size(), 0);
        vector<int> r(A.size(), 0);
        
        auto rIdx = A.size() - 1;
        l[0] = A[0];
        r[rIdx] = A[rIdx];
        --rIdx;
        for(auto i = 1; i<A.size(); ++i,--rIdx){
            l[i] = max(A[i], l[i - 1]);
            r[rIdx] = min(A[rIdx], r[rIdx + 1]);
        }
        
        for(auto i=0; i<A.size(); ++i){
            if(i+1 < A.size() && l[i] <= r[i+1]){
                ans = i;
                break;
            }
        }
        
        return ans + 1;
    }
};

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    vector<int> a = {1,1,1,0,6,12};
    cout<<solve.partitionDisjoint(a)<<endl;
    return 0;
}

