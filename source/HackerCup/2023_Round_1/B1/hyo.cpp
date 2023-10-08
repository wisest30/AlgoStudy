#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int SUM = 41;

vector<int> get_divisor(int p)
{
    vector<int> ret;
    for (auto i = 2; i <= SUM; ++i)
    {
        while (p % i == 0)
        {
            ret.push_back(i);
            p /= i;
        }
    }

    if (p != 1 || accumulate(ret.begin(), ret.end(), 0) > SUM)
    {
        return {-1};
    }

    return ret;
}

bool valid_divisor(const vector<int> &divisor)
{
    return divisor.empty() || divisor[0] != -1;
}

void print_ans(const vector<int> &ans)
{
    if (!valid_divisor(ans))
        cout << -1 << '\n';
    else
    {

        cout << ans.size() << ' ';
        for (auto x : ans)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

void solve(int TestCase)
{
    int p;
    cin >> p;

    auto divisor = get_divisor(p);
    auto su = accumulate(divisor.begin(), divisor.end(), 0);

    while (su < SUM && valid_divisor(divisor))
    {
        divisor.push_back(1);
        ++su;
    }

    print_ans(divisor);
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
