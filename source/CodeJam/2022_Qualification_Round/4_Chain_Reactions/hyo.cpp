#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

pair<ll, ll>
dfs(const vector<vector<int>>& g, 
    const vector<ll>& score, 
    int cur)
{
    pair<ll, ll> ret;
    ll min_val = INT64_MAX;

    for(auto& nxt : g[cur]) {
        auto sub_ret = dfs(g, score, nxt);
        ret.second += sub_ret.first + sub_ret.second;
        min_val = min(min_val, sub_ret.first);
    }

    if(min_val == INT64_MAX)
        min_val = 0;

    ret.first = max(min_val, score[cur]);
    ret.second -= min_val;

    return ret;
}

void solve(int TestCase) {
    int n;
    cin >> n;
    ++n;

    vector<vector<int>> g(n);
    vector<ll> score(n);
    for(auto i = 1; i < n; ++i)
        cin >> score[i];
    for(auto i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    auto ret = dfs(g, score, 0);
    cout << (ret.first + ret.second) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
