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
#include <unordered_map>


#include <algorithm>
#include <functional>
using namespace std;



/**
 
 895. Maximum Frequency Stack
 
 Implement FreqStack, a class which simulates the operation of a stack-like data structure.
 
 FreqStack has two functions:
 
 push(int x), which pushes an integer x onto the stack.
 pop(), which removes and returns the most frequent element in the stack.
 If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 
 
 Example 1:
 
 Input:
 ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
 [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
 Output: [null,null,null,null,null,null,null,5,7,5,4]
 Explanation:
 After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:
 
 pop() -> returns 5, as 5 is the most frequent.
 The stack becomes [5,7,5,7,4].
 
 pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
 The stack becomes [5,7,5,4].
 
 pop() -> returns 5.
 The stack becomes [5,7,4].
 
 pop() -> returns 4.
 The stack becomes [5,7].
 
 
 Note:
 
 Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
 It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
 The total number of FreqStack.push calls will not exceed 10000 in a single test case.
 The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
 The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
 */

/**
 
 36 / 36 test cases passed.
 Status: Accepted
 Runtime: 156 ms
 
 */


static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();

class FreqStack {
private:
    unordered_map<int, int> feq;
    unordered_map<int, stack<int>> feq_stk;
    int maxFeq;
public:
    FreqStack() {
        feq.clear();
        feq_stk.clear();
        maxFeq = -1;
    }
    
    void push(int x) {
        int f = ++feq[x];
        maxFeq = max(maxFeq,f);
        if(feq_stk.find(f) == feq_stk.end()){
            stack<int> st;
            feq_stk[f] = st;
        }
        feq_stk[f].push(x);
    }
    int pop() {
        int f = feq_stk[maxFeq].top();
        --feq[f];
        feq_stk[maxFeq].pop();
        if(feq_stk[maxFeq].empty()) --maxFeq;
        return f;
    }
};



int main(){
    
    
    return 0;
}


