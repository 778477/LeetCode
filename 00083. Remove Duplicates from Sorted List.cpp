
//Accepted	80 ms	cpp
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return NULL;
        ListNode *s,*p;
        s = head;
        p = s->next;
        while(p)
        {
            if(p->val == s->val)
            {
                s->next = p->next;
                free(p);
                p = s->next;
            }
            else
            {
                s = p;
                p = p->next;
            }
        }
        return head;
    }
};
