#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MAX_N = 10'000'000'000;

vector<ll> mobius_function(ll n)
{
    vector<ll> ret(n + 1);
    ret[1] = 1;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 2 * i; j <= n; j += i)
            ret[j] -= ret[i];
    return ret;
}

ll squre_free_count(ll n)
{
    auto m = mobius_function(sqrt(4 * MAX_N) + 10);
    ll ret = 0;
    for (ll i = 1; i * i <= n; ++i)
        ret += n / (i * i) * m[i];
    return ret;
}

ll non_squre_free_count(ll n)
{
    return n - squre_free_count(n);
}

void solve(int TestCase)
{
    ll n;
    cin >> n;

    ll l = 0, r = MAX_N * 4;
    while (l + 1 < r)
    {
        auto m = (l + r) / 2;
        if (non_squre_free_count(m) < n)
            l = m;
        else
            r = m;
    }

    cout << r << endl;
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
