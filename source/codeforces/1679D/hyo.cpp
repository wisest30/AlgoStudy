#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

ll n, m, k;
vector<int> A;
vector<vector<int>> g;
int dfs(vector<int>& visited, unordered_set<int>& in_path, int cur, int thrd) {
    if(in_path.count(cur)) return 1e9 + 1;
    if(visited[cur]) return visited[cur];
    visited[cur]++;
    in_path.insert(cur);

    for(auto nxt : g[cur]) {
        if(A[nxt] > thrd) continue;
        visited[cur] = max(visited[cur], dfs(visited, in_path, nxt, thrd) + 1);
    }

    in_path.erase(cur);
    return visited[cur];
}

void solve(int TestCase) {
    cin >> n >> m >> k;

    if(k > 1e9)
        k = 1e9;

    A = vector<int>(n);
    for(auto& x : A) cin >> x;

    g = vector<vector<int>>(n);
    for(auto i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
    }

    auto check = [&](auto thrd) {
        vector<int> visited(n);
        unordered_set<int> in_path;
        for(auto i = 0; i < n; ++i) {
            if(A[i] > thrd) continue;
            if(dfs(visited, in_path, i, thrd) >= k)
                return true;
        }

        return false;
    };

    ll l = 0, r = 1e9 + 1;
    while(l + 1 < r) {
        auto m = (l + r) / 2;
        if(check(m)) r = m;
        else l = m;
    }

    if(r == 1e9 + 1) cout << -1 << endl;
    else cout << r << endl;
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
