//
//  main.cpp
//  LeetCode
//
//  Created by 郭妙友 on 17/2/5.
//  Copyright © 2017年 miaoyou.gmy. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>
#include <iterator>

#include <numeric>
#include <iostream>
#include <unordered_set>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;


/*********************************
 
 1024. Video Stitching
 
 You are given a series of video clips from a sporting event that lasted T seconds.  These video clips can be overlapping with each other and have varied lengths.
 
 Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
 
 Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  If the task is impossible, return -1.
 
 
 
 Example 1:
 
 Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
 Output: 3
 Explanation:
 We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
 Then, we can reconstruct the sporting event as follows:
 We cut [1,9] into segments [1,2] + [2,8] + [8,9].
 Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
 Example 2:
 
 Input: clips = [[0,1],[1,2]], T = 5
 Output: -1
 Explanation:
 We can't cover [0,5] with only [0,1] and [0,2].
 Example 3:
 
 Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
 Output: 3
 Explanation:
 We can take clips [0,4], [4,7], and [6,9].
 Example 4:
 
 Input: clips = [[0,4],[2,8]], T = 5
 Output: 2
 Explanation:
 Notice you can have extra video after the event ends.
 
 
 Note:
 
 1 <= clips.length <= 100
 0 <= clips[i][0], clips[i][1] <= 100
 0 <= T <= 100
 
 *********************************/


class Solution {
public:
    int videoStitching(vector<vector<int>>& c, int T) {
        typedef pair<int,int> ii;
        const int INF = 1e9+7;
        
        vector<ii> p(101, {-1,-1});
        vector<int> dp(101, INF);
        
        int end = 0;
        for(auto&& ci : c){
            if(p[ci[0]].first == -1 || ci[1] - ci[0] > p[ci[0]].second - p[ci[0]].first){
                p[ci[0]] = {ci[0], ci[1]};
            }
            end = max(end, ci[1]);
        }
        
        if(end < T || p[0].first == -1) return -1;
        
        for(int i = 0; i<=p[0].second; ++i) dp[i] = 1;
        
        for(int i=1;i<=T;++i){
            for(int j = 0; j < p.size(); ++j){
                if(p[j].first == -1) continue;
                if(p[j].first > i) break;
                for(int k = p[j].first; k<=p[j].second; ++k){
                    dp[k] = min(dp[k], dp[i] + 1);
                }
            }
        }
        
        return dp[T] >= INF ? -1 : dp[T];
    }
};


int main(){
    
    Solution solution;
    //    [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]
    //    [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]]
    vector<vector<int>> clipes;
    clipes.push_back({0,1});
    clipes.push_back({6,8});
    clipes.push_back({0,2});
    clipes.push_back({5,6});
    clipes.push_back({0,4});
    clipes.push_back({0,3});
    clipes.push_back({6,7});
    clipes.push_back({1,3});
    clipes.push_back({4,7});
    clipes.push_back({1,4});
    clipes.push_back({2,5});
    clipes.push_back({2,6});
    clipes.push_back({3,4});
    clipes.push_back({4,5});
    clipes.push_back({5,7});
    clipes.push_back({6,9});
    cout<<solution.videoStitching(clipes, 9)<<endl;
    
    
    return 0;
}

