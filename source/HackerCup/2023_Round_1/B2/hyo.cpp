#include <bits/stdc++.h>

using namespace std;
using ll = long long;

unordered_map<ll, ll> dp, choice;
ll recur(ll su, ll p)
{
    if (su < 0)
        return INT_MAX;
    if (su == 0 && p > 1)
        return INT_MAX;
    if (su == 0 && p == 1)
        return 0;

    ll key = p * 100 + su;
    if (dp.find(key) != dp.end())
        return dp[key];

    auto &ret = dp[key];
    auto &ch = choice[key];
    ret = INT_MAX;
    ch = -1;
    for (auto i = 1; i <= su; ++i)
    {
        if (p % i)
            continue;
        auto sub_ret = recur(su - i, p / i);
        if (sub_ret == INT_MAX)
            continue;
        if (sub_ret + 1 < ret)
        {
            ret = sub_ret + 1;
            ch = i;
        }
    }

    return ret;
}

void solve(int TestCase)
{
    ll p;
    cin >> p;

    auto ret = recur(41, p);
    if (ret == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    ll su = 41;
    auto ch = choice[p * 100 + su];
    while (ch > 0)
    {
        ans.push_back(ch);
        p = p / ch;
        su = su - ch;
        ch = choice[p * 100 + su];
    }

    cout << ans.size() << " ";
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (auto i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
