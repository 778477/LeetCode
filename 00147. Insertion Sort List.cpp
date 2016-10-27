
//Accepted	204 ms	cpp
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head) return NULL;
        ListNode* p = head->next;
        head->next = NULL;
        if(!p) return head;
        ListNode* s;
        while(p)
        {
            s = head;
            if(p->val < s->val)
            {
                head = p;
                p = p->next;
                head->next = s;
                continue;
            }
            while(s->next && s->next->val < p->val) s = s->next;
            if(s->next == NULL)
            {
                s->next = p;
                p = p->next;
                s->next->next = NULL;
            }
            else
            {
                ListNode* tmp = p->next;
                p->next = s->next;
                s->next = p;
                p = tmp;
            }
        }
        return head;
    }
};

