//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//


#include <iostream>
#include <set>
#include <map>
#include <list>
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
 
 969. Pancake Sorting
 
 Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.
 
 Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
 
 
 
 Example 1:
 
 Input: [3,2,4,1]
 Output: [4,2,4,3]
 Explanation:
 We perform 4 pancake flips, with k values 4, 2, 4, and 3.
 Starting state: A = [3, 2, 4, 1]
 After 1st flip (k=4): A = [1, 4, 2, 3]
 After 2nd flip (k=2): A = [4, 1, 2, 3]
 After 3rd flip (k=4): A = [3, 2, 1, 4]
 After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted.
 Example 2:
 
 Input: [1,2,3]
 Output: []
 Explanation: The input is already sorted, so there is no need to flip anything.
 Note that other answers, such as [3, 3], would also be accepted.
 
 
 Note:
 
 1 <= A.length <= 100
 A[i] is a permutation of [1, 2, ..., A.length]
 
 */


/**
 
 策略： 最多两次翻转就可以让一个数到它应该存在的位置， 即 filps = 2 * A.length
 Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
 
 
 215 / 215 test cases passed.
 Status: Accepted
 Runtime: 8 ms
 
 */
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        
        for(auto size = A.size(); size > 0; --size){
            auto maxIdx = max_element(A.begin(), A.begin() + size) - A.begin();
            if(maxIdx + 1 == size) continue;
            ans.push_back(maxIdx + 1);
            reverse(A.begin(), A.begin() + maxIdx + 1);
            ans.push_back(size);
            reverse(A.begin(), A.begin() + size);
        }
        
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    Solution solve;
    
    vector<int> A = {3,2,4,1};
    vector<int> ans = solve.pancakeSort(A);
    for (int a : ans) cout<< a << endl;
    
    return 0;
}

