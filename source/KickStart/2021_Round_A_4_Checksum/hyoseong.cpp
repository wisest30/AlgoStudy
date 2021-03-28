#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class DisjointSet {
    vector<int> G, Gcnt;
public :
    DisjointSet(int n) : G(n), Gcnt(n)
    { iota(G.begin(), G.end(), 0); }

    int find(int x) {
        if(G[x] == x) return x;
        return G[x] = find(G[x]);
    }

    bool merge(int x, int y) {
        int gx = find(x), gy = find(y);
        if(gx == gy) return false;
        G[gy] = gx;
        Gcnt[gx] += Gcnt[gy];
        return true;
    }

    int cnt(int x) { return Gcnt[find(x)]; }
};

void solve(int TestCase) {
    int n;
    cin >> n;

    auto A = vector<vector<int>>(n, vector<int>(n));
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < n; ++j)
            cin >> A[i][j];
    
    auto B = vector<vector<int>>(n, vector<int>(n));
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < n; ++j)
            cin >> B[i][j];
    
    vector<int> R(n), C(n);
    for(auto i = 0; i < n; ++i) cin >> R[i];
    for(auto i = 0; i < n; ++i) cin >> C[i];

    auto edges = vector<array<int, 3>>(n);
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < n; ++j)
            if(A[i][j] == -1)
                edges.push_back({i, n + j, B[i][j]});

    sort(edges.begin(), edges.end(), [](auto& l, auto& r) {
        return l[2] > r[2];
    });

    ll ret = 0;
    DisjointSet ds(2 * n);
    for(auto& e : edges) {
        if(!ds.merge(e[0], e[1]))
            ret += e[2];
    }

    cout << ret << endl;
}
 
int main() {
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
