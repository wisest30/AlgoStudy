#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

ll edge_cnt;
constexpr int MOD = 1e9 + 7;

class DisjointSet {
    vector<int> G, Gcnt, l, r;
public :
    DisjointSet(int n) : G(n), Gcnt(n, 1), l(n), r(n)
    { 
        iota(G.begin(), G.end(), 0);
        iota(l.begin(), l.end(), 0);
        iota(r.begin(), r.end(), 1);
    }

    int find(int x) {
        if(G[x] == x) return x;
        return G[x] = find(G[x]);
    }

    bool merge(int x, int y) {
        int gx = find(x), gy = find(y);
        if(gx == gy) return false;
        G[gy] = gx;

        edge_cnt -= (ll)Gcnt[gx] * (Gcnt[gx] - 1) / 2;
        edge_cnt -= (ll)Gcnt[gy] * (Gcnt[gy] - 1) / 2;

        Gcnt[gx] += Gcnt[gy];
        
        edge_cnt += (ll)Gcnt[gx] * (Gcnt[gx] - 1) / 2;
        edge_cnt %= MOD;
        if(edge_cnt < 0) edge_cnt += MOD;

        l[gx] = min(l[gx], l[gy]);
        r[gx] = max(r[gx], r[gy]);
        return true;
    }

    int cnt(int x) { return Gcnt[find(x)]; }
    int left(int x) { return l[find(x)]; }
    int right(int x) { return r[find(x)]; }
};

void solve(int TestCase) {
    ll n, m;
    cin >> n >> m;

    edge_cnt = n * (n - 1) / 2;
    DisjointSet ds(n);
    ll ans = 1;
    for(auto i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(x > y) swap(x, y);

        while(ds.find(x) != ds.find(y)) {
            ds.merge(x, ds.right(x));
        }

         ans = ans * edge_cnt % MOD;
    }

    cout << ans << '\n';
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
