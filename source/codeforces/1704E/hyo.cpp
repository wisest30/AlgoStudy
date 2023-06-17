#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

vector<int> get_topsort(vector<vector<int>> &g) {
    vector<int> in_degree(g.size());
    for(auto u = 0; u < g.size(); ++u)
        for(auto v : g[u])
            in_degree[v]++;

    vector<int> ret;
    for (auto i = 0; i < g.size(); i++)
        if (in_degree[i] == 0)
            ret.push_back(i);

    for(auto i = 0; i < ret.size(); ++i)
    {
        int cur = ret[i];
        for(auto v : g[cur])
            if(--in_degree[v] == 0)
                ret.push_back(v);
    }

    assert(ret.size() == g.size());

    return ret;
}

void solve(int TestCase) {
    constexpr int MOD = 998244353;
    int n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    vector<vector<int>> g(n);
    for(auto i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
    }

    auto topsort = get_topsort(g);
    ll ret = 0;
    for(auto u : topsort) {
        while(A[u] > 0 && ret < n) {
            ret++;
            for(auto i = (int)topsort.size() - 1; i >= 0; --i) {
                auto cur = topsort[i];
                if(A[cur] == 0) continue;
                A[cur]--;
                for(auto nxt : g[cur])
                    A[nxt]++;
            }
        }
    }

    for(auto i = 0; i < topsort.size(); ++i) {
        auto time = A[topsort[i]];
        ret = (ret + time) % MOD;

        for(auto j = i; j < topsort.size(); ++j) {
            auto cur = topsort[j];
            auto d = min(time, A[cur]);
            A[cur] -= d;
            for(auto nxt : g[cur])
                A[nxt] += d;
        }

        for(auto& x : A)
            x %= MOD;
    }

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
