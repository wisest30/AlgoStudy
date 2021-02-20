class Solution {
public:
    int maximumScore(int a, int b, int c) {
        auto A = vector<int>{a, b, c};
        sort(A.begin(), A.end());
        
        A[2] = min(A[2], A[0] + A[1]);
        
        return (A[0] + A[1] + A[2]) / 2;
    }
};
