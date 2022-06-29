class Solution {
public:
    int countHousePlacements(int n) {
        constexpr int MOD = 1e9 + 7;
        
        long long dp[2] = {1, 2};
        for(auto i = 2; i <= n; ++i) {
            long long x = (dp[0] + dp[1]) % MOD;
            dp[0] = dp[1];
            dp[1] = x;
        }
        
        return dp[1] * dp[1] % MOD;
    }
};
