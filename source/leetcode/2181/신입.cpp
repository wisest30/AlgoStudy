/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        vector<int> vals;
        vector<int> newVal;
        
        while(head)
        {
            vals.push_back(head->val);
            head = head->next;
        }
        
        for(int i=0;i+1<vals.size();i++)
        {
            if(vals[i] == 0) newVal.push_back(0);
            else newVal.back() += vals[i];
        }
        
        ListNode* dummyHead = new ListNode();
        ListNode* dummyTail = dummyHead;
        
        for(int num : newVal)
        {
            dummyTail->next = new ListNode(num);
            dummyTail = dummyTail->next;
        }
        
        return dummyHead->next;
    }
};
