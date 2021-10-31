class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> A;
        while(head) {
            A.push_back(head->val);
            head = head->next;
        }
        
        int n = A.size();
        vector<int> B;
        for(auto i = 1; i < n-1; ++i) {
            if(A[i-1] < A[i] && A[i] > A[i+1]) B.push_back(i);
            else if(A[i-1] > A[i] && A[i] < A[i+1]) B.push_back(i);
        }
        
        if(B.size() < 2) return {-1, -1};
        
        auto ret = vector<int>{INT_MAX, B.back() - B[0]};
        for(auto i = 1; i < B.size(); ++i)
            ret[0] = min(ret[0], B[i] - B[i-1]);
        
        return ret;
    }
};
