#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX_BIT = 31;

void solve(int TestCase)
{
    int n;
    cin >> n;
    vector<int> A(n);
    int zcnt = 0;
    for (auto &x : A)
    {
        cin >> x;
        x %= 3;
        if (x == 0)
            ++zcnt;
    }

    int x;
    string s;
    if (zcnt <= n / 2)
    {
        x = 0;
        int one = 0;
        for (auto a : A)
        {
            if (a == 0 || one == n / 2)
                s.push_back('0');
            else
                ++one, s.push_back('1');
        }
    }
    else
    {
        x = 2;
        int zero = 0;
        for (auto a : A)
        {
            if (a == 0 && zero < n / 2)
                ++zero, s.push_back('0');
            else
                s.push_back('1');
        }
    }

    cout << x << endl;
    cout << s << endl;
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
