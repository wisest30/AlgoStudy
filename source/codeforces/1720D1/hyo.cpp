#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> dp, A;
int recur(int i)
{
    if (i == n)
        return 0;

    auto &ret = dp[i];
    if (ret != -1)
        return ret;

    ret = 1;
    for (auto j = i + 1; j < n; ++j)
    {
        if ((i & ~255) < (j & ~255))
            break;
        if ((A[i] ^ j) < (A[j] ^ i))
        {
            ret = max(ret, 1 + recur(j));
        }
    }

    return ret;
}

void solve(int TestCase)
{
    cin >> n;

    A = vector<int>(n);
    for (auto &x : A)
        cin >> x;

    dp = vector<int>(n, -1);
    auto ret = 0;
    for (auto i = 0; i < n; ++i)
        ret = max(ret, recur(i));

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
