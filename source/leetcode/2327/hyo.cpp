class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        constexpr int mod = 1e9 + 7;
        
        auto dp = vector<long long>(n);
        dp[0] = 1;
        
        for(auto i = 1; i < n; ++i)
            for(auto j = max(0, i - forget + 1); j <= i - delay; ++j)
                dp[i] = (dp[j] + dp[i]) % mod;
        
        return accumulate(dp.end() - forget, dp.end(), 0ll) % mod;
    }
};
