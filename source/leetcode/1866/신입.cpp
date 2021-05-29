class Solution {
public:
    typedef long long ll;

    const ll MOD = 1e9 + 7;
    ll fact[1'000 + 5] = { 1LL, };
    ll modInv[1'000 + 5] = { 1LL, };

    ll dp[1000 + 5][1000 + 5]{};
    ll prefixSum[1000 + 5][1000 + 5]{};

    ll getModInv(ll num)
    {
        ll pow = MOD - 2;
        ll ret = 1;
        ll mul = num;

        while (pow)
        {
            if (pow & 1) ret = (ret * mul) % MOD;
            mul = (mul * mul) % MOD;
            pow /= 2;
        }

        return ret;
    }

    int rearrangeSticks(int n, int k)
    {
        for (int i = 1; i <= 1000; i++)
        {
            fact[i] = (fact[i - 1] * i) % MOD;
            modInv[i] = getModInv(i);
        }

        for (int i = 0; i <= k; i++)
        {
            dp[i][i] = 1LL * getModInv(fact[i]);
            prefixSum[i][i] = dp[i][i];

            for (int j = i + 1; j <= n; j++)
            {
                if (i > 0) dp[j][i] = (prefixSum[j - 1][i - 1] * modInv[j]) % MOD;
                prefixSum[j][i] = (prefixSum[j - 1][i] + dp[j][i]) % MOD;
            }
        }

        ll ans = (dp[n][k] * fact[n]) % MOD;
        return ans;
    }
};
