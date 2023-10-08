#include <bits/stdc++.h>

using namespace std;
using ll = long long;

double dist(double x0, double x1, double x2, double x3)
{
    return (x2 + x3) / 2.0 - (x0 + x1) / 2.0;
}

void solve(int TestCase)
{
    int n;
    cin >> n;

    vector<double> A(n);
    for (auto &x : A)
        cin >> x;

    sort(A.begin(), A.end());

    double ans;
    if (A.size() == 5)
        ans = max(dist(A[0], A[1], A[2], A[4]), dist(A[0], A[2], A[3], A[4]));
    else
        ans = dist(A[0], A[1], A[A.size() - 2], A.back());

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
