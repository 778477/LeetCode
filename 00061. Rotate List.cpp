
//	Accepted	12 ms	cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(!k) return head;
        if(!(head->next)) return head;
        vector<ListNode *> V;
        ListNode *tmp = head;
        while(tmp){
            V.push_back(tmp);
            tmp = tmp->next;
            V.back()->next = NULL;
        }
        if(k%V.size() == 0) k = (int)V.size();
        else k%=V.size();
        head = V[V.size() - k];
        ListNode *node = head;
        for(int i = (int)V.size() - k + 1; i < V.size(); i++){
            node->next = V[i];
            node = node->next;
        }
        
        for(int i=0;i<(int)V.size() - k;i++){
            node->next = V[i];
            node = node->next;
        }
        return head;
    }
};
