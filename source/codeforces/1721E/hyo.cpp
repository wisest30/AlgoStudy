#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> get_pi(const string &s)
{
    int n = s.size(), j = 0;
    auto pi = vector<int>(n);
    for (auto i = 1; i < n; ++i)
    {
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            pi[i] = ++j;
    }
    return pi;
}

void solve(int TestCase)
{
    string s;
    cin >> s;

    auto pi = get_pi(s);
    vector<vector<int>> p(s.size(), vector<int>(26));
    for (auto i = 0; i < s.size(); ++i)
    {
        for (auto j = 0; j < 26; ++j)
        {
            if (i && s[i] != 'a' + j)
                p[i][j] = p[pi[i - 1]][j];
            else
                p[i][j] = i + (s[i] == 'a' + j);
        }
    }

    int q;
    cin >> q;
    for (auto i = 0; i < q; ++i)
    {
        string t;
        cin >> t;

        for (auto j = 0; j < t.size(); ++j)
        {
            p.push_back(vector<int>(26));
            for (auto k = 0; k < 26; ++k)
            {
                if (t[j] != 'a' + k)
                    p[s.size() + j][k] = p[pi[s.size() + j - 1]][k];
                else
                    p[s.size() + j][k] = s.size() + j + (t[j] == 'a' + k);
            }
            pi.push_back(p[pi[s.size() + j - 1]][t[j] - 'a']);
            cout << pi.back() << ' ';
        }
        cout << endl;

        while (p.size() > s.size())
        {
            p.pop_back();
            pi.pop_back();
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
