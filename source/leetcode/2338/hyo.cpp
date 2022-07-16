namespace {
    class Combination2 {
        using T = unsigned long long;
        T MOD;
        vector<T> fact;
    public :
        Combination2(int n, T MOD = 0)
        : MOD(MOD), fact(n+1) {
            fact[0] = 1;
            for(auto i = 1; i <= n; ++i)
                fact[i] = fact[i-1] * i % MOD;
        }

        T pow_mod(long long x, long long y, long long mod) {
            auto ret=1ll;
            while (y) {
                    if (y % 2)
                        ret = ret * x % mod;
                    x =  x * x % mod;
                    y /= 2;
                }
            return ret;
        }

        T nCr(int n, int r) {
            return fact[n] * pow_mod(fact[n-r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
        }
    };
}

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        constexpr int MOD = 1e9 + 7;
        constexpr int MAX_M = 15;
        constexpr int MAX_N = 10000;

        Combination2 comb(MAX_N, MOD);
        long long ret = maxValue;

        auto dp = vector<vector<long long>>(MAX_M, vector<long long>(maxValue + 1));
        fill(dp[1].begin(), dp[1].end(), 1);

        for(auto len = 2; len < min(n + 1, MAX_M); ++len) {
            for(auto last = 2; last <= maxValue; ++last) {
                for(auto i = 1; i * i <= last; ++ i) {
                    if(last % i == 0) {
                        auto j = last / i;
                        dp[len][last] = (dp[len][last] + dp[len - 1][i]) % MOD;
                        if(i != j && j != last)
                            dp[len][last] = (dp[len][last] + dp[len - 1][j]) % MOD;
                    }
                }

                ret = (ret + comb.nCr(n - 1, len - 1) * dp[len][last] % MOD) % MOD;
            }
        }
        
        return ret;
    }
};
