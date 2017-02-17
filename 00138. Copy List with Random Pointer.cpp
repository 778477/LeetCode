//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <cstdlib>


#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 138. Copy List with Random Pointer
 
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
 Return a deep copy of the list.
 
 */

/**
 
 Hash Table / Linked List
 
 
 12 / 12 test cases passed.
 Status: Accepted
 Runtime: 56 ms
 
 */



//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        
        map<RandomListNode *, RandomListNode *> mp;
        RandomListNode *copyHead = new RandomListNode(head->label);
        mp[head] = copyHead;
        
        RandomListNode *tmpHead = copyHead;
        RandomListNode *orginalHead = head;
        
        while(orginalHead->next){
            tmpHead->next = new RandomListNode(orginalHead->next->label);
            mp[orginalHead->next] = tmpHead->next;
            tmpHead = tmpHead->next;
            orginalHead = orginalHead->next;
        }
        
        
        tmpHead = copyHead;
        orginalHead = head;
        
        while(orginalHead){
            if(orginalHead->random){
                tmpHead->random = mp[orginalHead->random];
            }
            orginalHead = orginalHead->next;
            tmpHead = tmpHead->next;
        }
        
        return copyHead;
        
    }
};

int main(){
    
    return 0;
}
