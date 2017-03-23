//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 
 447. Number of Boomerangs
 
 Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
 
 Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
 
 Example:
 Input:
 [[0,0],[1,0],[2,0]]
 
 Output:
 2
 
 Explanation:
 The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 
 */


/**
 
 哈希出现相同距离的个数
 
 hypot http://www.cplusplus.com/reference/cmath/hypot/
 
 31 / 31 test cases passed.
 Status: Accepted
 Runtime: 415 ms
 
 */


class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        
        for( auto& p : points ){
            unordered_map<double, unsigned> table;
            for ( auto& q : points ){
                ans += 2 * table[hypot(p.first-q.first,p.second-q.second)]++;
            }
        }
        
        return ans;
    }
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(){
    return 0;
}
