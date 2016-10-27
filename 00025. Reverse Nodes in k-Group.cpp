
//Accepted    35 ms    cpp
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head) return NULL;
        
        stack<ListNode *> nodeStack;
        vector<ListNode *> reverseNodes;
        while(head){
            nodeStack.push(head);
            head = head->next;
            nodeStack.top()->next = NULL;
            if(nodeStack.size() == k){
                while (!nodeStack.empty()) {
                    reverseNodes.push_back(nodeStack.top());
                    nodeStack.pop();
                }
            }
        }
        
        vector<ListNode *> anotherNodes;
        while(!nodeStack.empty()){
            anotherNodes.push_back(nodeStack.top());
            nodeStack.pop();
        }
        
        for_each(anotherNodes.rbegin(), anotherNodes.rend(), [&](ListNode *node){
            reverseNodes.push_back(node);
        });
        
        head = reverseNodes[0];
        ListNode *tmp = head;
        for(int i=1;i<reverseNodes.size();i++)
        {
            tmp->next = reverseNodes[i];
            tmp = reverseNodes[i];
        }
        
        return head;
    }
};

