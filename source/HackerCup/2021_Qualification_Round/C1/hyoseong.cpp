#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n;
vector<int> A;
vector<vector<int>> G;

int dfs(int cur, int prev) {
    int ret = 0;
    for(auto nxt : G[cur]) {
        if(nxt == prev) continue;
        ret = max(ret, dfs(nxt, cur));
    }

    ret += A[cur];
    return ret;
}

void solve(int TestCase) {
    cin >> n;
    A.resize(n);
    for(auto& x : A) cin >> x;

    G = vector<vector<int>>(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> S;
    for(auto nxt : G[0])
        S.push_back(dfs(nxt, 0));
    
    sort(S.begin(), S.end(), greater<int>());

    int ret = A[0];
    for(auto i = 0; i < min(2, (int)S.size()); ++i)    
        ret += S[i];
    
    cout << ret << endl;
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
