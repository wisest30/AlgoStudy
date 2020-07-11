class Solution {
public:
    int numSubseq(vector<int>& A, int t) {
        constexpr int MOD = 1e9+7;
        auto B = vector<long long>(A.size()+1);
        B[0] = 1;
        for(auto i = 1; i < B.size(); ++i) B[i] = B[i-1] * 2 % MOD;
        sort(A.begin(), A.end());
        long long ret = 0;
        for(auto i = 0; i < A.size(); ++i) {
            auto p = upper_bound(A.begin(), A.end(), t - A[i]) - A.begin();
            if(p <= i) break;
            ret += B[p - i - 1];
            ret %= MOD;
        }
        return ret;
    }
};
