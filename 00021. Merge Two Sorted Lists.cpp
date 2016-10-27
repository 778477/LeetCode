
//Accepted    21 ms    cpp
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1 || !l2){
            if(!l1 && !l2) return NULL;
            
            return l1 ? l1 : l2;
        }
        
        ListNode *head;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        ListNode *tmp = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }
            else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        
        if(l1) tmp->next = l1;
        if(l2) tmp->next = l2;
        return head;
    }
};


