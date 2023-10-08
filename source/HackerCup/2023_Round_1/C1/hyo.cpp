#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void flip(string &s, int i)
{
    s[i] = (s[i] - '0') ^ 1 + '0';
}

void press(string &s, int i)
{
    for (auto j = i; j < s.size(); j += i + 1)
        flip(s, j);
}

void solve(int TestCase)
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q;
    cin >> q;
    vector<int> cnt(n);
    for (auto i = 0; i < q; ++i)
    {
        int x;
        cin >> x;
        --x;
        cnt[x]++;
    }

    for (auto i = 0; i < n; ++i)
        if (cnt[i] % 2)
            press(s, i);

    int ans = 0;
    for (auto i = 0; i < n; ++i)
        if (s[i] == '1')
            press(s, i), ++ans;

    cout << ans << endl;
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
