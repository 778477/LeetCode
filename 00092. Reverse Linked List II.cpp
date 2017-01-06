//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
using namespace std;


/*
 92. Reverse Linked List II
 Total Accepted: 94201
 Total Submissions: 315979
 Difficulty: Medium
 Contributors: Admin
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 
 Subscribe to see which companies asked this question
 
 **/

/*
 Accepted	3 ms	cpp
 **/
//Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m == n) return head;
        
        int startIdx = 1,betweenLen = n-m+1;
        ListNode *tmp,*pre;
        tmp = head;
        pre = NULL;
        
        while(startIdx != m){
            pre = tmp;
            tmp = tmp->next;
            startIdx++;
        }
        
        
        vector<int> Arr((betweenLen),0);
        for(int i=0;i<betweenLen;i++){
            Arr[i] = tmp->val;
            tmp = tmp->next;
        }
        reverse(Arr.begin(), Arr.end());
        
        startIdx = 0;
        if(!pre){
            pre = (ListNode *)malloc(sizeof(ListNode));
            pre->val = Arr[startIdx++];
            head = pre;
        }
        
        for(int i=startIdx;i<betweenLen;i++){
            ListNode *node = (ListNode *)malloc(sizeof(ListNode));
            node->val = Arr[i];
            pre->next = node;
            pre = pre->next;
        }
        
        pre->next = tmp;
        
        return head;
    }
};
