#include<bits/stdc++.h>
 
using namespace std;
 
constexpr long long MOD = 1e9+7;
int n, m;
vector<vector<int>> edges;
vector<long long> P, C;
long long dfs(int cur, int prev) {
    long long ret = 1;
    for(auto& nxt : edges[cur]) {
        if(nxt == prev)
            continue;
        
        ret += dfs(nxt, cur);
    }
 
    if(cur)
        C[cur-1] = ret * (n - ret);
    return ret;
}
void solve(int TestCase) {
    cin >> n;
    edges = vector<vector<int>>(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
 
    cin >> m;
    P = vector<long long>(m);
    for(auto i = 0; i < m; ++i)
        cin >> P[i];
    while(P.size() < n-1)
        P.push_back(1);
    sort(P.begin(), P.end());
    while(P.size() > n-1) {
        int idx = (int)P.size() - 1;
        P[idx-1] *= P[idx];
        P[idx-1] %= MOD;
        P.pop_back();
    }
    
    C = vector<long long>(n-1);
    dfs(0, -1);
    sort(C.begin(), C.end());
 
    long long ret = 0;
    for(auto i = 0; i < n-1; ++i)
        ret = (ret + P[i] * C[i] % MOD) % MOD;
 
    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
    //    cout << "Case #"<< i << ": ";
        solve(i);
    }
}
