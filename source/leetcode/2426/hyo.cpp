class FenwickTree {
public:
    int N;
    vector<long long> f;
    FenwickTree(int N) : N(N), f(vector<long long>(N+10)) {}
    void upd(int i, long long val) {
        assert(i >= 0 && i < N);
        for(; i < f.size(); i |= i+1) f[i] += val;
    }

    long long get(int i) {
        assert(i >= 0 && i <= N);
        if(i == 0) return 0;
        i--;

        long long ret = 0;
        for(; i >= 0; i = (i & (i+1)) - 1) ret += f[i];
        return ret;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        constexpr int M = 50000;
        auto n = nums1.size();
        FenwickTree ft(100000);
        long long ret = 0;
        for(auto i = 0; i < n; ++i) {
            ret += ft.get(nums1[i] - nums2[i] + diff + M + 1);
            ft.upd(nums1[i] - nums2[i] + M, 1);
        }
        return ret;
    }
};
