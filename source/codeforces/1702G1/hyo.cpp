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
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    } 

    function<int(int, int, set<int>&)> find_start = [&](int cur, int prev, set<int>& s) {
        for(auto nxt : g[cur]) {
            if(nxt == prev) continue;
            auto sub_ret = find_start(nxt, cur, s);
            if(sub_ret != -1)
                return sub_ret;
        }

        if(s.count(cur)) return cur;
        else return -1;
    };

    function<int(int, int, set<int>&)>
    dfs = [&](int cur, int prev, set<int>& s) {
        int cnt = 0;
        for(auto nxt : g[cur]) {
            if(nxt == prev) continue;
            auto sub_ret = dfs(nxt, cur, s);
            if(sub_ret == -1) return -1;
            else if(sub_ret > 0) ++cnt;
        }

        if(cnt > 1) return -1;
        else if(cnt == 1 || s.count(cur)) return 1;
        else return 0;
    };

    int q;
    cin >> q;
    for(auto i = 0; i < q; ++i) {
        set<int> s;
        int k;
        cin >> k;
        for(auto j = 0; j < k; ++j) {
            int u;
            cin >> u;
            --u;
            s.insert(u);
        }

        auto start = find_start(0, -1, s);
        auto ret = dfs(start, -1, s);
        if(ret == -1) cout << "NO\n";
        else cout << "YES\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
