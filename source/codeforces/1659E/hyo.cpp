#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class DisjointSet {
    vector<int> G, Gcnt;
public :
    DisjointSet(int n) : G(n), Gcnt(n, 1)
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
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    for(auto& e : edges) {
        cin >> e[0] >> e[1] >> e[2];
        e[0]--, e[1]--;
    }

    int q;
    cin >> q;
    vector<array<int, 3>> query(q);
    for(auto& q : query) {
        cin >> q[0] >> q[1];
        q[0]--, q[1]--;
        q[2] = 2;
    }

    vector<DisjointSet> ds(30, DisjointSet(n));
    for(auto i = 0; i < 30; ++i)
        for(auto& e : edges)
            if(e[2] & (1 << i))
                ds[i].merge(e[0], e[1]);

    for(auto i = 0; i < q; ++i)
        for(auto j = 0; j < 30; ++j)
            if(ds[j].find(query[i][0]) == ds[j].find(query[i][1]))
                query[i][2] = 0;

    vector<bool> has_even(n);
    for(auto i = 1; i < 30; ++i) {
        vector<bool> group_has_even(n);
        for(auto& e : edges)
            if(e[2] % 2 == 0)
                group_has_even[ds[i].find(e[0])] = group_has_even[ds[i].find(e[1])] = true;
        
        for(auto& q : query)
            if(q[2] && group_has_even[ds[i].find(q[0])])
                q[2] = 1;
    }

    for(auto q : query)
        cout << q[2] << "\n";
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
