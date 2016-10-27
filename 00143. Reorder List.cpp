
//	Accepted	280 ms	cpp
class Solution {
private:
    vector<ListNode *> listNodeVector;
public:
    Solution()
    {
        listNodeVector.clear();
    }
    void reorderList(ListNode *head) {
        ListNode *tmp = head;
        while(tmp)
        {
            listNodeVector.push_back(tmp);
            ListNode* fix = tmp;
            tmp = tmp->next;
            fix->next = NULL;
        }
        
        // 只有一个节点，无需翻转
        if(listNodeVector.size() < 2) return;
        
        int end = (int)listNodeVector.size() - 1;
        int star = 0;
        head = listNodeVector[star];
        tmp = head;
        while(star < end)
        {
            tmp->next = listNodeVector[end];
            tmp = listNodeVector[end];
            star++;
            if(star == end) break;
            tmp->next = listNodeVector[star];
            tmp = listNodeVector[star];
            end--;
            if(end == star) break;
        }
    }
};
