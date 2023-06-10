#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    constexpr int MAX_BIT = 20;
    vector<vector<int>> g(n), spt(n, vector<int>(MAX_BIT, -1));
    vector<int> dth(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    } 

    function<void(int, int, int)> dfs = [&](auto cur, auto prev, auto d) {
        dth[cur] = d, spt[cur][0] = prev;
        for(auto nxt : g[cur]) 
            if(nxt != prev) 
                dfs(nxt, cur, d+1);
    };
    dfs(0, -1, 0);

    for(auto i = 1; i < MAX_BIT; ++i) 
        for(auto j = 0; j < n; ++j) 
            if(spt[j][i-1] != -1)
                spt[j][i] = spt[spt[j][i-1]][i-1];

    auto lca = [&](auto u, auto v) {
        if(dth[u] > dth[v]) 
            swap(u, v);

        for(auto i = MAX_BIT - 1; i >= 0; --i) 
            if(dth[v] - (1 << i) >= dth[u]) 
                v = spt[v][i];

        for(auto i = MAX_BIT - 1; i >= 0; --i) 
            if(spt[u][i] != spt[v][i]) u = spt[u][i], v = spt[v][i];
        return u == v ? u : spt[u][0];
    };

    int q;
    cin >> q;
    for(auto i = 0; i < q; ++i) {
        int k;
        cin >> k;

        vector<int> S(k);
        for(auto& x : S) {
            cin >> x;
            --x;
        }

        sort(S.begin(), S.end(), [&](auto l, auto r) {
            return dth[l] > dth[r];
        });

        vector<int> A, B;
        for(auto i = 0; i < k; ++i) {
            if(lca(S[0], S[i]) == S[i])
                A.push_back(S[i]);
            else
                B.push_back(S[i]);
        }

        auto ans = true;
        if(B.empty()) {
            cout << "YES\n";
            continue;
        }

        for(auto b : B) {
            if(lca(B[0], b) != b) {
                ans = false;
                break;
            }
        }

        if(!ans) {
            cout << "NO\n";
            continue;
        }

        auto l = lca(A[0], B[0]);
        if(dth[l] > dth[A.back()])
            cout << "NO\n";
        else
            cout << "YES\n";
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
