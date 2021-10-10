class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(1 << n), right(1 << n);

        auto su = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> A(n+1), B(n+1);

        for(auto i = 0; i < n; ++i) {
            left[1 << i] = nums[i];
            right[1 << i] = nums[i + n];
        }
        for(auto mask = 0; mask < (1 << n); ++mask) {
            left[mask] = left[mask & -mask] + left[mask & (mask - 1)];
            right[mask] = right[mask & -mask] + right[mask & (mask - 1)];
            int cnt = __builtin_popcount(mask);
            A[cnt].push_back(left[mask]);
            B[cnt].push_back(right[mask]);
        }        
        
        for(auto& x : A) sort(x.begin(), x.end());
        for(auto& x : B) sort(x.begin(), x.end());
        
        auto ret = INT_MAX;
        for(auto cnt0 = 0; cnt0 <= n; ++cnt0) {
            auto cnt1 = n - cnt0;
            for(auto x : A[cnt0]) {
                auto val = su / 2 - x;
                auto p = lower_bound(B[cnt1].begin(), B[cnt1].end(), val);
                if(p != B[cnt1].end()) {
                    auto a = x + *p;
                    auto b = su - a;
                    ret = min(ret, abs(a - b));
                }
                if(p != B[cnt1].begin()) {
                    auto a = x + *prev(p);
                    auto b = su - a;
                    ret = min(ret, abs(a - b));
                }
            }
        }

        return ret;
    }
};
