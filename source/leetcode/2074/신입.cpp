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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> values;
        
        while(head) values.push_back(head->val), head = head->next;
        
        int sum = 0;
        
        for(int i=1;;i++)
        {
            if(sum + i >= values.size()) break;
            sum += i;
            int len = min(values.begin() + sum + i + 1, values.end()) - values.begin() - sum;
            if(len%2==0) reverse(values.begin()+sum, min(values.begin()+sum+i+1, values.end()));
        }
        
        ListNode* dummyHead = new ListNode;
        ListNode* dummyTail = dummyHead;
        
        for(int i=0;i<values.size();i++)
        {
            ListNode* newNode = new ListNode(values[i]);
            dummyTail->next = newNode;
            dummyTail = dummyTail->next;
        }
        
        return dummyHead->next;
    }
};
