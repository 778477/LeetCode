
//	Accepted	8 ms	cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> vals;
        
        ListNode *tmp = head;
        while(tmp){
            vals.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        
        vector<int> smallVals;
        vector<int> bigVals;
        
        for_each(vals.begin(), vals.end(), [&](const int num){
            if(num >= x){
                bigVals.push_back(num);
            }
            else{
                smallVals.push_back(num);
            }
        });
        
        
        for_each(bigVals.begin(), bigVals.end(), [&](const int num){
            smallVals.push_back(num);
        });
        
        int len = (int)smallVals.size();
        if(len >= 1) head->val = smallVals[0];
        tmp = head;
        for(int i=1;i<len;i++){
            ListNode *node = new ListNode(smallVals[i]);
            tmp->next = node;
            tmp = node;
        }
        return head;
    }
};
