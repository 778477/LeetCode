//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 155. Min Stack
 
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 Example:
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> Returns -3.
 minStack.pop();
 minStack.top();      --> Returns 0.
 minStack.getMin();   --> Returns -2.
 
 */


/*
 18 / 18 test cases passed.
 Status: Accepted
 Runtime: 29 ms
 */


class MinStack {
public:
    void push(int x) {
        Stack.push(x);
        if(minStack.empty() || x <= minStack.top()){
            minStack.push(x);
        }
    }
    
    void pop() {
        int tmp = Stack.top();
        Stack.pop();
        if(tmp == minStack.top()){
            minStack.pop();
        }
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    stack<int> minStack;
    stack<int> Stack;
};


int main(){
    
    return 0;
}
