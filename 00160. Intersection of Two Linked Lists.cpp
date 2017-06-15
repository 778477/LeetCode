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
 
 160. Intersection of Two Linked Lists
 DescriptionHintsSubmissionsSolutions
 Total Accepted: 129911
 Total Submissions: 426812
 Difficulty: Easy
 Contributor: LeetCode
 Write a program to find the node at which the intersection of two singly linked lists begins.
 
 
 For example, the following two linked lists:
 
 A:          a1 → a2
 ↘
 c1 → c2 → c3
 ↗
 B:     b1 → b2 → b3
 begin to intersect at node c1.
 
 
 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
 
 */


/*
 42 / 42 test cases passed.
 Status: Accepted
 Runtime: 56 ms
 */




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        
        ListNode *tmp = headA;
        while (tmp) {
            lenA++;
            tmp = tmp->next;
        }
        
        tmp = headB;
        while(tmp)
        {
            lenB++;
            tmp = tmp->next;
        }
        
        if(lenB > lenA)
        {
            int len = lenB - lenA;
            tmp = headB;
            while(len--)
                tmp = tmp->next;
            headB = tmp;
        }
        
        if(lenA > lenB)
        {
            int len = lenA - lenB;
            tmp = headA;
            while(len--)
                tmp = tmp->next;
            headA = tmp;
        }
        
        
        while(headA && headB)
        {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main(){
    
    return 0;
}
