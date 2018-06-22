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

#include <set>
#include <map>
#include <stack>
#include <queue>

#include <cmath>
#include <vector>
#include <string>

#include <numeric>
#include <iostream>
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 855. Exam Room
 
 In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.
 
 When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)
 
 Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.
 
 
 
 Example 1:
 
 Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
 Output: [null,0,9,4,2,null,5]
 Explanation:
 ExamRoom(10) -> null
 seat() -> 0, no one is in the room, then the student sits at seat number 0.
 seat() -> 9, the student sits at the last seat number 9.
 seat() -> 4, the student sits at the last seat number 4.
 seat() -> 2, the student sits at the last seat number 2.
 leave(4) -> null
 seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
 ​​​​​​​
 
 Note:
 
 1 <= N <= 10^9
 ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
 Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.
 */

/**
 
 128 / 128 test cases passed.
 Status: Accepted
 Runtime: 37 ms
 
 
 使用 set 维护一个有序的入座顺序
 
 */




class ExamRoom {
private:
    set<int> students;
    int n;
public:
    ExamRoom(int N) {
        students.clear();
        n = N;
    }
    
    int seat() {
        
        int seat = 0;
        
        if(!students.empty()){
            
            int dist = 0, tmp = 0, pre = -1;
            
            for(auto i = students.begin(); i!=students.end(); ++i){
                if(pre == -1){
                    tmp = *i - 0;
                    if(tmp > dist){
                        dist = tmp ;
                        seat = 0;
                    }
                } else {
                    tmp = (*i - pre) / 2;
                    if(tmp > dist){
                        dist = tmp;
                        seat =(*i-pre)/2 + pre;
                    }
                }
                pre = *i;
            }
            
            
            if(n - 1 - pre > dist){
                seat = n-1;
            }
        }
        students.insert(seat);
        return seat;
    }
    
    void leave(int p) {
        students.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
int main(){
    
    ExamRoom room(10);
    cout<<room.seat()<<endl;
    cout<<room.seat()<<endl;
    cout<<room.seat()<<endl;
    cout<<room.seat()<<endl;
    room.leave(4);
    room.leave(0);
    cout<<room.seat()<<endl;
    return 0;
}
