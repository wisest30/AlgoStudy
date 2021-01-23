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
    ListNode* swapNodes(ListNode* head, int k) {
        auto h = head;
        vector<ListNode*> A;
        while(h) {
            A.push_back(h);
            h = h->next;
        }
        
        swap(A[k-1]->val, A[(int)A.size() - k]->val);
        return head;
    }
};
