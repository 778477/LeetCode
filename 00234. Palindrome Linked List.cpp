//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <cstdlib>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
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
 
 234. Palindrome Linked List
 
 Total Accepted: 103357
 Total Submissions: 319005
 Difficulty: Easy
 Contributor: LeetCode
 
 Given a singly linked list, determine if it is a palindrome.
 
 Follow up:
 Could you do it in O(n) time and O(1) space?
 
 
 */


/*
 
 Could you do it in O(n) time and O(1) space?
 Sorry, I Can't
 
 26 / 26 test cases passed.
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
    bool isPalindrome(ListNode* head) {
        
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        
        vector<int> rnums = nums;
        reverse(rnums.begin(), rnums.end());
        
        for( size_t i = 0; i < nums.size() ; ++i){
            if(nums[i] != rnums[i]){
                return false;
            }
        }
        
        return true;
    }
};

int main(){
    
    
    vector<int> nums{0,1};
    //    vector<int> nums{1,1,1,5,1,1};
    //    vector<int> nums{1,2,3,4,5,6,7};
    // test plan
    ListNode *head = NULL,*tmp = NULL;
    for(int num : nums){
        if(!tmp){
            tmp = new ListNode(num);
            head = tmp;
        } else {
            tmp->next = new ListNode(num);
            tmp = tmp->next;
        }
    }
    
    
    
    Solution solve;
    cout<<solve.isPalindrome(head)<<endl;
    
    
    return 0;
}
