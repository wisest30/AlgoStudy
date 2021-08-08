#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
constexpr int MOD = 1e9 + 7;
int n, k;
vector<vector<int>> G;
 
ll dfs(int cur, int prev, int d) {
    if(d == 0)
        return 1;
    
    ll ret = 0;
    for(auto nxt : G[cur]) {
        if(nxt == prev)
            continue;
        
        ret += dfs(nxt, cur, d - 1);
    }
 
    return ret;
}
 
ll recur(vector<vector<int>>& dp, const vector<int>& A, int i, int remain) {
    if(remain == 0) return 1;
    if(i == A.size()) return 0;
    
    auto& ret = dp[i][remain];
    if(ret != -1) return ret;
 
    ret = recur(dp, A, i+1, remain) + recur(dp, A, i + 1, remain - 1) * A[i] % MOD;
    ret %= MOD;
 
    return ret;
}
 
ll kMul(const vector<int>& A) {
    auto dp = vector<vector<int>>(A.size(), vector<int>(k+1, -1));
    auto ret = recur(dp, A, 0, k);
    return ret;
}
 
ll evenDis(int d) {
    ll ret = 0;
    for(auto u = 0; u < n; ++u) {
        vector<int> A;
        for(auto nxt : G[u]) {
            auto cnt = dfs(nxt, u, d / 2 - 1);
            if(cnt > 0)
                A.push_back(cnt);
        }
 
        ll add = kMul(A);
        ret = (ret + add) % MOD;
    }
 
    return ret;
}
 
void solve(int TestCase) {
    cin >> n >> k;
    G = vector<vector<int>>(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
 
    ll ret = 0;
    if(k == 2)
        ret = (ll) n * (n-1) / 2;
    else {
        for(auto d = 2; d < n; d += 2)
            ret = (ret + evenDis(d)) % MOD;
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
