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
 
 328. Odd Even Linked List
 
 Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 
 You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 
 Example:
 Given 1->2->3->4->5->NULL,
 return 1->3->5->2->4->NULL.
 
 Note:
 The relative order inside both the even and odd groups should remain as it was in the input.
 The first node is considered odd, the second node even and so on ...
 
 Credits:
 Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
 
 Subscribe to see which companies asked this question.
 
 
 */


/**
 
 70 / 70 test cases passed.
 Status: Accepted
 Runtime: 26 ms
 
 */



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *fast = NULL, *even = NULL;
        ListNode *tmp = head;
        if(head && head->next){
            even = fast = head->next;
        }
        while (fast) {
            if(fast->next){
                tmp->next = fast->next;
                tmp = tmp->next;
            } else {
                break;
            }
            
            if(tmp->next){
                fast->next = tmp->next;
                fast = fast->next;
            } else {
                break;
            }
        }
        
        if(fast) fast->next = NULL;
        if(tmp) tmp->next = even;
        
        return head;
    }
};

int main(){
    Solution solve;
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    
    ListNode *ans = solve.oddEvenList(head);
    
    while(ans){
        cout<<ans->val<<endl;
        ans = ans->next;
    }
    
    return 0;
}
