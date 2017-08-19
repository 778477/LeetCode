/**
 Status: Accepted
 Runtime: 4 ms
 Submitted: 1 year, 3 months ago
*/

void deleteNode(struct ListNode* node) {
    struct ListNode* tmp = node->next;
    
    if(tmp){
        node->val = tmp->val;
        node->next = tmp->next;
        free(tmp);
    }
}
