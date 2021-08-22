#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class DisjointSet {
    vector<int> G;
    vector<char> V;
public :
    DisjointSet(int n) : G(n), V(n)
    { iota(G.begin(), G.end(), 0); }

    void set_val(int x, char v) { V[find(x)] = v; }

    int get_val(int x) { return V[find(x)]; }

    int find(int x) {
        if(G[x] == x) return x;
        return G[x] = find(G[x]);
    }

    bool merge(int x, int y) {
        int gx = find(x), gy = find(y);
        if(gx == gy) return false;
        G[gy] = gx;
        if(V[gy]) V[gx] = V[gy];
        return true;
    }
};

void solve(int TestCase) {
    int r, c;
    cin >> r >> c;

    auto A = vector<string>(r);
    for(auto& s : A) cin >> s;

    vector<vector<int>> left, right, up, down;
    left = right = up = down = vector<vector<int>>(r, vector<int>(c));

    for(auto y = 0; y < r; ++y) {
        int l = 0;
        for(auto x = 0; x < c; ++x) {
            if(A[y][x] == '#') l = x+1;
            else left[y][x] = l;
        }
        int ri = c;
        for(auto x = c - 1; x >= 0; --x) {
            if(A[y][x] == '#') ri = x;
            else right[y][x] = ri;
        }
    } 

    for(auto x = 0; x < c; ++x) {
        int u = 0;
        for(auto y = 0; y < r; ++y) {
            if(A[y][x] == '#') u = y+1;
            else up[y][x] = u;
        }
        int d = r;
        for(auto y = r-1; y >= 0; --y) {
            if(A[y][x] == '#') d = y;
            else down[y][x] = d;
        }
    }

    int n = r * c;
    auto ds = DisjointSet(n);

    for(auto y = 0; y < r; ++y)
        for(auto x = 0; x < c; ++x)
            if(A[y][x] >= 'A' && A[y][x] <= 'Z')
                ds.set_val(y * c + x, A[y][x]);

    for(auto y = 0; y < r; ++y) {
        for(auto x = 0; x < c; ++x) {
            if(A[y][x] == '#') continue;

            auto id = y * c + x;
            auto nx = left[y][x] + right[y][x] - 1 - x;
            auto id_hori = y * c + nx;
            ds.merge(id, id_hori);

            auto ny = up[y][x] + down[y][x] - 1 - y;
            auto id_verti = ny * c + x;
            ds.merge(id, id_verti);
        }
    }

    int cnt = 0;
    for(auto y = 0; y < r; ++y) {
        for(auto x = 0; x < c; ++x) {
            auto val = ds.get_val(y * c + x);
            if(val && A[y][x] == '.')
                A[y][x] = val, cnt++;
        }
    }

    cout << cnt << endl;
    for(auto& s : A) cout << s << endl;
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
