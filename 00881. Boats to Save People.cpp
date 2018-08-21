//
//  main.cpp
//  LeetcodeWhiteboard
//
//  Created by miaoyou.gmy on 2018/7/13.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/**
 
 881. Boats to Save People
 
 The i-th person has weight people[i], and each boat can carry a maximum weight of limit.
 
 Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.
 
 Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)
 
 
 
 Example 1:
 
 Input: people = [1,2], limit = 3
 Output: 1
 Explanation: 1 boat (1, 2)
 Example 2:
 
 Input: people = [3,2,2,1], limit = 3
 Output: 3
 Explanation: 3 boats (1, 2), (2) and (3)
 Example 3:
 
 Input: people = [3,5,3,4], limit = 5
 Output: 4
 Explanation: 4 boats (3), (3), (4), (5)
 Note:
 
 1 <= people.length <= 50000
 1 <= people[i] <= limit <= 30000
 
 */


/**
 
 77 / 77 test cases passed.
 Status: Accepted
 Runtime: 72 ms
 
 */

static auto _ = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int ans = 0, left = 0, right = (int)people.size() - 1;
        
        
        while(left <= right){
            
            while(people[left] + people[right] > limit && right > left){
                --right;
                ++ans;
            }
            
            if(right > left && people[left] + people[right] <= limit){
                ++left;
                --right;
                ++ans;
            } else if(left == right){
                ++ans;
                ++left;
                --right;
            }
            
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solve;
    vector<int> people = {3,2,2,1};
    cout<<solve.numRescueBoats(people, 3)<<endl;
    
    return 0;
}

