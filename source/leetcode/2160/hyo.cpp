class Solution {
public:
    int minimumSum(int num) {
        auto A = vector<int>{num / 1000, num / 100 % 10, num / 10 % 10, num % 10};
        sort(A.begin(), A.end());
        return A[0] * 10 + A[1] * 10 + A[2] + A[3];
    }
};
