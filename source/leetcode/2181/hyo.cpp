class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        auto cur = head;
        
        while(true) {
            if(cur->val == 0) {
                while(cur->next && cur->next->val) {
                    cur->val += cur->next->val;
                    cur->next = cur->next->next;
                }
            }
            
            if(!cur->next->next) {
                cur->next = nullptr;
                break;
            }

            cur = cur->next;
        }
        
        return head;
    }
};
