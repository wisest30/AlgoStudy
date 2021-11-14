class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<ListNode*> A;
        auto h = head;
        while(h) {
            A.push_back(h);
            h = h->next;
        }
        
        int n = A.size();
        for(auto g = 1;;g++) {
            int left = g * (g - 1) / 2;
            int right = g * (g + 1) / 2;
            if(left >= n) break;
            if(right > n) right = n;
            
            int len = right - left;
            if(len % 2 == 0)
                reverse(A.begin() + left, A.begin() + right);
        }
        
        for(auto i = 0; i < n-1; ++i) {
            A[i]->next = A[i+1];
        }
        A.back()->next = nullptr;
        
        return A[0];
    }
};
