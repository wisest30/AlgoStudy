#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int TestCase)
{
    int ia, ib, ic;
    cin >> ia >> ib >> ic;

    __float128 a = ia, b = ib, c = ic;

    auto sinx = [](__float128 x)
    {
        constexpr __float128 pi = 3.1415926535897932384626q;
        while (x > pi * 2)
            x -= pi * 2;

        __float128 q = x, p = 1, ret = x;
        for (auto i = 2; i <= 30; i += 2)
        {
            q *= -x * x;
            p *= i * (i + 1);
            ret += q / p;
        }

        return ret;
    };

    auto check = [&](__float128 m)
    {
        return a * m + b * sinx(m) - c <= 0;
    };

    __float128 l = (c - b) / a;
    __float128 r = (c + b) / a;
    int count = 100;
    while (count--)
    {
        __float128 m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }

    auto ans = double(__int128_t(1000000 * l + 0.5)) / 1000000.0;
    cout << fixed;
    cout.precision(6);
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
        // cout << "Case #" << i << ": ";
        solve(i);
    }
}
