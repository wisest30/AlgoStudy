#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int TestCase)
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;

    int ret = 0;
    for (auto i = 30; i >= 0; --i)
    {
        unordered_map<int, int> cnts;
        int cnt0 = 0, cnt1 = 0, p = (ret | (1 << i));
        for (auto x : A)
            cnts[x & p]++;
        for (auto x : B)
            cnts[~x & p]--;
        auto all_zero = all_of(cnts.begin(), cnts.end(), [&](auto pa)
                               { return pa.second == 0; });
        if (all_zero)
            ret |= (1 << i);
    }

    cout << ret << endl;
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
        // cout << "Case #"<< i << ": ";
        solve(i);
    }
}
