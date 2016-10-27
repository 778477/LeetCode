
//Accepted	128 ms	cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        ListNode *s = head;
        ListNode *q = head;
        s = s->next;
        if(!s) return false;
        q = q->next->next;
        
        
        while(s && q)
        {
            if(s == q) return true;
            s = s->next;
            if(q->next == NULL) return false;
            q = q->next->next;
        }
        return false;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(!hasCycle(head)) return NULL;
        
        set<ListNode *> unionSet;
        ListNode *tmp = head;
        unionSet.insert(tmp);
        tmp = tmp->next;
        while(!unionSet.count(tmp))
        {
            unionSet.insert(tmp);
            tmp = tmp->next;
        }
        return tmp;
    }
};
