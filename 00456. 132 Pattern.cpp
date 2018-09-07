
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
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <functional>

using namespace std;

/**
 
 456. 132 Pattern
 
 Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
 
 Note: n will be less than 15,000.
 
 Example 1:
 Input: [1, 2, 3, 4]
 
 Output: False
 
 Explanation: There is no 132 pattern in the sequence.
 Example 2:
 Input: [3, 1, 4, 2]
 
 Output: True
 
 Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
 Example 3:
 Input: [-1, 3, 2, 0]
 
 Output: True
 
 Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 
 
 */


/**
 
 95 / 95 test cases passed.
 Status: Accepted
 Runtime: 268 ms
 
 */

static auto _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        if(nums.size() < 3) return false;
        
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        
        left[0] = nums[0];
        right[nums.size() - 1] = nums[nums.size() - 1];
        
        for(auto i=1; i<nums.size(); ++i){
            left[i] = min(left[i - 1], nums[i]);
            right[nums.size() - 1 - i] = min(right[nums.size() - i], nums[nums.size() - 1 - i]);
        }
        
        
        for(auto j = 1; j < nums.size() - 1; ++j){
            if(left[j - 1] < nums[j] && nums[j] > right[j+1]){
                if(right[j+1] > left[j-1]){
                    return true;
                }
                int k = j+1;
                while(k < nums.size()){
                    if(nums[j] > nums[k] && nums[k] > left[j-1]) return true;
                    ++k;
                }
            }
        }
        
        return false;
    }
};

/**
 
 [[5,5],[4,6],[2,6]] => 2
 {1,2},{2,3} => 2
 */

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    Solution solve;
    vector<int> nums = {5,4,1,2,3};
    
    cout<<solve.find132pattern(nums)<<endl;
    
    
    return 0;
}
