class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> A(n);
        iota(A.begin(), A.end(), 1);
        
        int cur = 0;
        while(A.size() > 1) {
            cur = (cur + k - 1) % A.size();
            A.erase(A.begin() + cur);
        }
        
        return A[0];
    }
};
