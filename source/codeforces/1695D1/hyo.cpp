#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    function<int(int, int)> dfs = [&](int cur, int p) {
        int sum_val = 0, leaf_child = 0;
        for(auto nxt : g[cur]) {
            if(nxt == p) continue;
            auto sub_ret = dfs(nxt, cur);
            sum_val += sub_ret;
            if(sub_ret == 0)
                leaf_child++;
        }

        auto ret = sum_val + leaf_child;
        if(leaf_child > 0)
            ret--;

        return ret;
    };

    int ret = INT_MAX;
    for(auto root = 0; root < n; ++root)
        ret = min(ret, dfs(root, -1) + 1);

    cout << ret << endl;
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
