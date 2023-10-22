#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int TestCase)
{
    int n;
    cin >> n;

    deque<int> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;

    deque<int> dq(n);
    for (auto i = 0; i < n; ++i)
    {
        if (A[i] == B[i])
            dq[i] = 0;
        else if (A[i] < B[i])
            dq[i] = -1;
        else
            dq[i] = 1;
    }

    int front_cnt[3] = {0, 0, 0}, back_cnt[3] = {0, 0, 0};
    for (auto i = 0; i < n / 2; ++i)
        front_cnt[dq[i] + 1]++;
    for (auto i = (n + 1) / 2; i < n; ++i)
        back_cnt[dq[i] + 1]++;

    auto process = [&]()
    {
        auto p = dq.front();
        auto q = dq[n / 2];
        auto r = dq[(n + 1) / 2];

        dq.pop_front();
        front_cnt[p + 1]--;
        front_cnt[q + 1]++;

        dq.push_back(-p);
        back_cnt[r + 1]--;
        back_cnt[-p + 1]++;

        B.push_back(A.front());
        A.pop_front();
        A.push_back(B.front());
        B.pop_front();
    };

    auto check = [&](auto cnt)
    {
        for (auto i = 0; i < n; ++i)
            if (A[i] != B[n - 1 - i])
                return false;

        return true;
    };

    if (n % 2 == 0)
    {
        auto ret = 0;
        while (ret < 2 * n && !(front_cnt[0] == n / 2 && back_cnt[2] == n / 2))
        {
            process();
            ++ret;
        }

        if (ret < 2 * n && check(ret))
            cout << ret << endl;
        else
            cout << -1 << endl;
    }
    else
    {
        auto ret = 0;
        while (ret < 2 * n && !(dq[n / 2] == 0 && front_cnt[0] == n / 2 && back_cnt[2] == n / 2))
        {
            process();
            ++ret;
        }

        if (ret < 2 * n && front_cnt[0] == n / 2 && back_cnt[2] == n / 2 && check(ret))
            cout << ret << endl;
        else
            cout << -1 << endl;
    }
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
