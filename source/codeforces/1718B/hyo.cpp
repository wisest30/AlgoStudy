#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int TestCase)
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto &x : A)
        cin >> x;

    ll a_sum = accumulate(A.begin(), A.end(), 0ll);
    vector<ll> P({0, 1});
    ll su = 1;
    while (su < a_sum)
    {
        ll x = P[P.size() - 2] + P[P.size() - 1];
        su += x;
        P.push_back(x);
    }

    if (su != a_sum)
    {
        cout << "NO\n";
        return;
    }

    priority_queue<ll> pq(A.begin(), A.end());
    while (P.size() > 1)
    {
        if (P.back() > pq.top())
        {
            cout << "NO\n";
            return;
        }

        ll x = pq.top();
        pq.pop();
        x -= P.back();
        P.pop_back();

        if (x == 0)
            continue;
        if (x > pq.top() || pq.empty())
        {
            cout << "NO\n";
            return;
        }
        pq.push(x);
    }

    cout << "YES\n";
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
