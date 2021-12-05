class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        auto n = 0;
        auto cur = head;
        while(cur) {
            cur = cur->next;
            ++n;
        }
        
        if(n == 1)
            return nullptr;
        
        cur = head;
        auto i = 0;
        while(cur) {
            if(i == n / 2 - 1)
                cur->next = cur->next->next;
            cur = cur->next;
            ++i;
        }
        
        return head;
    }
};
