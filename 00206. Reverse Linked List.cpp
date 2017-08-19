/**
 Status: Accepted
 Runtime: 0 ms
 Submitted: 1 year, 3 months ago
*/
struct ListNode* reverseList(struct ListNode* head) {
    if(!head) return head;
    struct ListNode *pre,*cur,*next;
    pre = NULL;
    cur = head;
    next = head->next;
    
    while(cur && next){
        cur->next = pre;
        pre = cur;
        
        cur = next;
        next = cur->next;
    }
    cur->next = pre;
    return cur;
}
