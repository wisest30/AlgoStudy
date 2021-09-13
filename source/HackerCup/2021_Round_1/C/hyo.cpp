#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

using V = vector<ll>;
using V2 = vector<V>;
using V3 = vector<V2>;
using V4 = vector<V3>;

static constexpr int MOD = 1e9 + 7;
static constexpr int MAX_C = 21;

vector<vector<pair<ll, ll>>> G;
V2 dummy;
V3 dp;
V4 ldp, rdp;

V2 merge(const V2& a, const V2& b) {
    auto ret = V2(2, V(MAX_C));

    for(auto i = 0; i < MAX_C; ++i) {
        ret[0][i] = (a[0][i] + b[0][i]) % MOD;
    }

    auto a_sum = a[0];
    auto b_sum = b[0];
    for(auto i = 1; i < MAX_C; ++i) {
        a_sum[i] = (a_sum[i] + a_sum[i-1]) % MOD;
        b_sum[i] = (b_sum[i] + b_sum[i-1]) % MOD;
    }

    for(auto i = 0; i < MAX_C; ++i) {
        ret[1][i] = (a[1][i] + b[1][i]) % MOD;
        ret[1][i] = (ret[1][i] + a[0][i] * b[0][i] % MOD) % MOD;

        ll add = (b_sum.back() - b_sum[i] + MOD) % MOD * a[0][i] % MOD;
        ret[1][i] = (ret[1][i] + add) % MOD;

        ll add2 = (a_sum.back() - a_sum[i] + MOD) % MOD * b[0][i] % MOD;
        ret[1][i] = (ret[1][i] + add2) % MOD;
    }

    return ret;
}

V2 add_node(const V2& a, ll node, ll c) {
    auto ret = a;
    for(auto i = c + 1; i < MAX_C; ++i) {
        ret[0][c] = (ret[0][c] + a[0][i]) % MOD;
        ret[0][i] = 0;
    }

    ret[0][c] = (ret[0][c] + 1) % MOD;

    for(auto i = 0; i < MAX_C; ++i) {
        ret[1][i] = (ret[1][i] + ret[0][i]) % MOD;
    }

    return ret;
}

void dfs(int cur, int prev) {
    for(auto [nxt, c] : G[cur]) {
        if(nxt == prev) {
            continue;
        }

        dfs(nxt, cur);
    }

    dp[cur] = V2(2, V(MAX_C));
    for(auto [nxt, c] : G[cur]) {
        if(nxt == prev) {
            ldp[cur].push_back(ldp[cur].empty() ? dummy : ldp[cur].back());
            continue;
        }

        auto tdp = add_node(dp[nxt], cur, c);
        dp[cur] = merge(dp[cur], tdp);
        ldp[cur].push_back(dp[cur]);
    }

    dp[cur] = V2(2, V(MAX_C));
    for(auto i = (int)G[cur].size() - 1; i >= 0; --i) {
        auto [nxt, c] = G[cur][i];
        if(nxt == prev) {
            rdp[cur].push_back(rdp[cur].empty() ? dummy : rdp[cur].back());
            continue;
        }

        auto tdp = add_node(dp[nxt], cur, c);
        dp[cur] = merge(dp[cur], tdp);
        rdp[cur].push_back(dp[cur]);
    }

    reverse(rdp[cur].begin(), rdp[cur].end());
}

ll ans;
void dfs2(int cur, int prev, V2& p, ll pc) {
    if(cur != 0) {
        ll mul = 0;
        for(auto i = 0; i < dp[cur][1].size(); ++i) {
            mul = (mul + dp[cur][1][i] * i % MOD) % MOD;
            mul = (mul + p[1][i] * i % MOD) % MOD;
        }

        ans = ans * mul % MOD;
        p = add_node(p, cur, pc);
    }

    for(auto i = 0; i < G[cur].size(); ++i) {
        auto [nxt, c] = G[cur][i];
        if(nxt == prev) {
            continue;
        }

        auto left = i == 0 ? V2(2, V(MAX_C)) : ldp[cur][i-1];
        auto nxt_p = merge(p, left);

        auto right = i == (int)G[cur].size() - 1 ? V2(2, V(MAX_C)) : rdp[cur][i+1];
        nxt_p = merge(nxt_p, right);

        dfs2(nxt, cur, nxt_p, c);
    }
}

void solve(int TestCase) {
    int n;
    cin >> n;

    G = vector<vector<pair<ll, ll>>>(n);
    for(auto i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    dp = V3(n);
    dummy = V2(2, V(MAX_C));
    ldp = V4(n);
    rdp = V4(n);
    dfs(0, -1);

    ans = 1;
    auto p = V2(2, V(MAX_C));
    dfs2(0, -1, p, -1);
    cout << ans << endl;
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
