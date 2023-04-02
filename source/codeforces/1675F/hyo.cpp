#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    int x, y;
    cin >> x >> y;
    x--, y--;

    set<int> A;
    for(auto i = 0; i < k; ++i) {
        int a;
        cin >> a;
        a--;
        A.insert(a);
    }

    // think y as things but subtract distance x to y.
    A.insert(y);

    vector<vector<int>> g(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto ret = 0;
    function<bool(int, int, int)> dfs = [&](int cur, int par, int d) {
        auto has_a = A.count(cur);
        if(cur == y)
            ret -= d;

        for(auto nxt : g[cur]) {
            if(nxt == par) continue;
            has_a |= dfs(nxt, cur, d + 1);
        }

        if(has_a && cur != x)
            ret += 2;

        return has_a;
    };

    dfs(x, -1, 0);

    cout << ret << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
