class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int> v1,v2,tmp;

        while(l1 != NULL)
        {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            v2.push_back(l2->val);
            l2 = l2->next;
        }

        if(v1.size() > v2.size())
        {
            tmp = v1;
            v1 = v2;
            v2 = tmp;
        }

        int base = 0,carry = 0;
        int len1 = v1.size()-1,len2 = v2.size()-1;
        int index = 1;
        tmp.clear();
        base = v1[0] + v2[0];
        carry = base / P;
        base = base % P;
        tmp.push_back(base);
        while(index <= len1)
        {
            base = v1[index] + v2[index] + carry;
            carry = base / P;
            base = base % P;
            tmp.push_back(base);
            index++;
        }

        while(index <= len2)
        {
            base = v2[index++] + carry;
            carry = base / P;
            base = base % P;
            tmp.push_back(base);
        }

        if(carry)
            tmp.push_back(carry);


//        for(size_t i = 0 ; i < tmp.size();i++)
//            printf("%d ",tmp[i]);


        ListNode* head = (ListNode*)malloc(sizeof(ListNode));
        head->val = tmp[0];
        head->next = NULL;
        if(tmp.size() == 1) return head;

        ListNode* t = head;
//        t = head;
        for(size_t i=1;i<tmp.size();i++)
        {
            ListNode* p = (ListNode*)malloc(sizeof(ListNode));
            p->val = tmp[i];
            p->next = NULL;
            t->next = p;
            t = p;
        }

        return head;
    }
private:
    static const int P = 10;
};
