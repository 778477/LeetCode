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

#include <numeric>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 841. Keys and Rooms
 
 There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room.
 
 Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
 
 Initially, all the rooms start locked (except for room 0).
 
 You can walk back and forth between rooms freely.
 
 Return true if and only if you can enter every room.
 
 Example 1:
 
 Input: [[1],[2],[3],[]]
 Output: true
 Explanation:
 We start in room 0, and pick up key 1.
 We then go to room 1, and pick up key 2.
 We then go to room 2, and pick up key 3.
 We then go to room 3.  Since we were able to go to every room, we return true.
 Example 2:
 
 Input: [[1,3],[3,0,1],[2],[0]]
 Output: false
 Explanation: We can't enter the room with number 2.
 Note:
 
 1 <= rooms.length <= 1000
 0 <= rooms[i].length <= 1000
 The number of keys in all rooms combined is at most 3000.
 */


/**
 
 key - room 表示图的联通性
 
 拓扑排序
 
 66 / 66 test cases passed.
 Status: Accepted
 Runtime: 14 ms
 
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numberOfRoom = (int)rooms.size();
        vector<bool> vis(numberOfRoom,false);
        queue<int> Q;
        Q.push(0);
        vis[0] = true;
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            
            numberOfRoom--;
            if(numberOfRoom == 0) return true;
            for(int r : rooms[now]){
                if(!vis[r]){
                    Q.push(r);
                    vis[r] = true;
                }
            }
        }
        
        return false;
    }
};


int main(){
    Solution solve;
    
    vector<vector<int>> rooms;
    rooms.push_back({1,3});
    rooms.push_back({3,0,1});
    rooms.push_back({2});
    rooms.push_back({0});
    
    cout<<solve.canVisitAllRooms(rooms)<<endl;
    
    return 0;
}
