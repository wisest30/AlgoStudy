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
    ListNode* deleteMiddle(ListNode* head) {
        int listSz = 0;
        ListNode* temp = head;
        
        while(temp)
        {
            listSz++;
            temp = temp->next;
        }
        
        if(listSz == 1) return NULL;
        
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        
        ListNode* cur = dummyHead;
        
        for(int i=0;i<listSz/2;i++) cur = cur->next;        
        
        temp = cur->next;
        cur->next = cur->next->next;
        
        delete temp;
        delete dummyHead;
        
        return head;
    }
};
