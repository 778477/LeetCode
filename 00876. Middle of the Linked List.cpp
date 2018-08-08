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
 
 
 876. Middle of the Linked List
 
 Given a non-empty, singly linked list with head node head, return a middle node of linked list.
 
 If there are two middle nodes, return the second middle node.
 
 
 
 Example 1:
 
 Input: [1,2,3,4,5]
 Output: Node 3 from this list (Serialization: [3,4,5])
 The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
 Note that we returned a ListNode object ans, such that:
 ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
 Example 2:
 
 Input: [1,2,3,4,5,6]
 Output: Node 4 from this list (Serialization: [4,5,6])
 Since the list has two middle nodes with values 3 and 4, we return the second one.
 
 
 Note:
 
 The number of nodes in the given list will be between 1 and 100.
 */

/**
 
 15 / 15 test cases passed.
 Status: Accepted
 Runtime: 0 ms
 
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        
        while(fast){
            if(fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
            } else if(fast->next){
                fast = fast->next;
                slow = slow->next;
            } else {
                break;
            }
        }
        
        return slow;
    }
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();


int main(){
    
    
    Solution solve;
    ListNode *head = new ListNode(1);
    ListNode *tmp = head;
    for(int i=2;i<5;++i){
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    
    ListNode *mid = solve.middleNode(head);
    cout<<mid->val<<endl;
    
    return 0;
}
