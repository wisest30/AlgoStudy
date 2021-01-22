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
    int getLength(ListNode* head) {
        ListNode* ptr = head;
        int len = 0;
        while (ptr != nullptr && ptr != 0) {
            len++;
            ptr = ptr->next;
        }
        return len;
    }
    ListNode* getNth(ListNode* head, int pos) {
        ListNode* ptr = head;
        for (int i=0; i < pos; i++) {
            ptr = ptr->next;
        }
        return ptr;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int len = getLength(head);
        ListNode* a = getNth(head, k - 1);
        ListNode* b = getNth(head, len - k);
        swap(a->val, b->val);
        return head;
    }
};
