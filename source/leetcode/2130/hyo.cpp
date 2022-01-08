class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> A;
        while(head) {
            A.push_back(head->val);
            head = head->next;
        }
        int ret = 0;
        for(auto i = 0; i < A.size() / 2; ++i) ret = max(ret, A[i] + A[(int)A.size() - 1 - i]);
        return ret;
    }
};
