#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

class Combination2
{
    using T = unsigned long long;
    T MOD;
    vector<T> fact;

public:
    Combination2(int n, T MOD = 0)
        : MOD(MOD), fact(n + 1)
    {
        fact[0] = 1;
        for (auto i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
    }

    T pow_mod(long long x, long long y, long long mod)
    {
        auto ret = 1ll;
        while (y)
        {
            if (y % 2)
                ret = ret * x % mod;
            x = x * x % mod;
            y /= 2;
        }
        return ret;
    }

    T nCr(int n, int r)
    {
        return fact[n] * pow_mod(fact[n - r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
    }

    T factorial(int n)
    {
        return fact[n];
    }
};

void solve(int TestCase)
{
    ll n, m;
    cin >> n >> m;

    vector<ll> D(n);
    for (auto &x : D)
        cin >> x;

    Combination2 comb(max(n, m), MOD);

    ll d_sum = accumulate(D.begin(), D.end(), 0ll);
    if (d_sum % 2 == 1)
    {
        ll ans = comb.pow_mod(m, n, MOD);
        cout << ans << endl;
        return;
    }

    ll couple = 0, solo = 0, distance = 0;
    for (auto i = 0, j = 0; i < n; ++i)
    {
        while (distance < d_sum / 2)
        {
            distance += D[j];
            j = (j + 1) % n;
        }

        if (distance == d_sum / 2)
            ++couple;
        else
            ++solo;

        distance -= D[i];
    }

    couple /= 2;

    ll ans = 0;
    for (auto i = 0ll; i <= couple; ++i)
    {
        if (i > m)
            break;

        ll add = comb.nCr(couple, i) * comb.nCr(m, i) % MOD;
        add = add * comb.factorial(i) % MOD;
        add = add * comb.pow_mod(m - i, couple - i + solo, MOD) % MOD;
        if (add > 0)
            add = add * comb.pow_mod(m - i - 1, couple - i, MOD) % MOD;

        ans = (ans + add) % MOD;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (auto i = 1; i <= t; ++i)
    {
        // cout << "Case #"<< i << ": ";
        solve(i);
    }
}
