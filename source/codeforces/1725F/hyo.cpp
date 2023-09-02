#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX_BIT = 31;

void solve(int TestCase)
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> A(n);
    for (auto &x : A)
        cin >> x.first >> x.second;

    vector<ll> ans(MAX_BIT);
    for (auto i = 0; i < MAX_BIT; ++i)
    {
        ll p = 1 << i;

        vector<pair<ll, ll>> B;
        for (auto &a : A)
        {
            if (a.second - a.first + 1 >= p)
            {
                ++ans[i];
                continue;
            }

            ll x0 = a.first % p;
            ll x1 = a.second % p;

            if (x1 < x0)
                B.push_back({0, 1});
            B.push_back({x0, 1});
            B.push_back({x1 + 1, -1});
        }

        sort(B.begin(), B.end());
        ll cnt = 0, max_cnt = 0;
        for (auto j = 0; j < B.size(); ++j)
        {
            cnt += B[j].second;
            if (j == (int)B.size() - 1 || B[j].first != B[j + 1].first)
                max_cnt = max(max_cnt, cnt);
        }

        ans[i] += max_cnt;
    }

    int q;
    cin >> q;
    for (auto i = 0; i < q; ++i)
    {
        ll w;
        cin >> w;
        for (auto j = 0; j < MAX_BIT; ++j)
        {
            if (w & (1 << j))
            {
                cout << ans[j] << '\n';
                break;
            }
        }
    }
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
