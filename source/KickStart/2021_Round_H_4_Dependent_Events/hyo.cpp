#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
constexpr ll pow_mod(ll x, ll y, ll mod) {
    auto ret=1ll;
    while (y) {
        if (y % 2) ret = ret * x % mod;
        x =  x * x % mod;
        y /= 2;
    }
    return ret;
}

constexpr ll inv = pow_mod(1000000, MOD - 2, MOD);

int n, q, k;
vector<vector<int>> par, g;
vector<ll> prob;
vector<vector<pair<ll, ll>>> P;
vector<int> depth;

void construct_depth(int cur, int d) {
    depth[cur] = d;
    for(auto nxt : g[cur])
        construct_depth(nxt, d + 1);
}

void construct_prob(int cur, int prev) {
    if(cur == 0)
        prob[cur] = k * inv % MOD;
    else {
        prob[cur] = (prob[prev] * P[0][cur].first % MOD 
                    + (1 - prob[prev] + MOD) % MOD * P[0][cur].second % MOD) % MOD;
    }

    for(auto nxt : g[cur])
        construct_prob(nxt, cur);
}

int get_lca(int u, int v) {
    if(u == v) return u;
    if(depth[u] > depth[v]) return get_lca(v, u);
    else if(depth[u] == depth[v]) {
        for(auto i = 31; i >= 0; --i) {
            auto p = par[i][u];
            auto q = par[i][v];
            if(p != q) return get_lca(p, q);
        }
        return par[0][u];
    }
    else {
        for(auto i = 31; i >= 0; --i) {
            auto p = par[i][v];
            if(p != -1 && depth[p] >= depth[u])
                return get_lca(u, p);
        }
        assert(false);
        exit(0);
    }
}

ll get_prob(int anc, bool event, int cur) {
    if(anc == cur)
        return event ? 1 : 0;
    
    for(auto i = 31; i >= 0; --i) {
        int p = par[i][cur];
        if(p == -1 || depth[p] < depth[anc]) continue;

        auto x = get_prob(anc, event, p);
        auto y = (1 - x + MOD) % MOD;
        return (x * P[i][cur].first % MOD + y * P[i][cur].second % MOD) % MOD;
    }

    assert(false);
    exit(0);
}

void solve(int TestCase) {
    cin >> n >> q >> k;
    par = vector<vector<int>>(32, vector<int>(n, -1));
    g = vector<vector<int>>(n);
    P = vector<vector<pair<ll, ll>>>(32, vector<pair<ll, ll>>(n));

    P[0][0].first = P[0][0].second = k * inv % MOD;
    for(auto i = 1; i < n; ++i) {
        cin >> par[0][i] >> P[0][i].first >> P[0][i].second;
        par[0][i]--;
        g[par[0][i]].push_back(i);
        P[0][i].first *= inv;
        P[0][i].first %= MOD;
        P[0][i].second *= inv;
        P[0][i].second %= MOD;
    }

    for(auto i = 1; i < 32; ++i) {
        for(auto j = 0; j < n; ++j) {
            if(par[i-1][j] != -1)
                par[i][j] = par[i-1][par[i-1][j]];
            if(par[i][j] != -1) {
                ll a0 = P[i-1][j].first * P[i-1][par[i-1][j]].first % MOD;
                ll a1 = P[i-1][j].second * (1 - P[i-1][par[i-1][j]].first + MOD) % MOD;
                P[i][j].first = (a0 + a1) % MOD;

                a0 = P[i-1][j].first * P[i-1][par[i-1][j]].second % MOD;
                a1 = P[i-1][j].second * (1 - P[i-1][par[i-1][j]].second + MOD) % MOD;
                P[i][j].second = (a0 + a1) % MOD;
            }
        }
    }

    depth = vector<int>(n);
    construct_depth(0, 0);

    prob = vector<ll>(n);
    construct_prob(0, -1);

    vector<ll> ret;
    for(auto i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        auto lca = get_lca(u, v);
        ll a0 = get_prob(lca, true, u);
        ll a1 = get_prob(lca, true, v);

        ll b0 = a0 * a1 % MOD * prob[lca] % MOD;

        a0 = get_prob(lca, false, u);
        a1 = get_prob(lca, false, v);

        ll b1 = a0 * a1 % MOD * (1 - prob[lca] + MOD) % MOD;

        ll ans = (b0 + b1) % MOD;
        ret.push_back(ans);
    }

    for(auto r : ret) cout << r << ' ';
    cout << '\n';
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
