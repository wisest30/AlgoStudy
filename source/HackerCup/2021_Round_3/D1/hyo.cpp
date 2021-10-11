#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class DisjointSet {
    vector<int> G, Gcnt;
    vector<bool> counted;
public :
    DisjointSet(int n) : G(n), Gcnt(n, 1), counted(n)
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
        counted[gx] = counted[gx] | counted[gy];
        return true;
    }
    int cnt(int x) { return Gcnt[find(x)]; }
    void set_count(int x) { counted[find(x)] = true; }
    bool is_count(int x) { return counted[find(x)]; }
};

void solve(int TestCase) {
    int r, c;
    cin >> r >> c;

    auto H = vector<vector<int>>(r, vector<int>(c));
    for(auto y = 0; y < r; ++y) for(auto x = 0; x < c; ++x) cin >> H[y][x];

    auto S = vector<vector<int>>(r, vector<int>(c));
    for(auto y = 0; y < r; ++y) for(auto x = 0; x < c; ++x) cin >> S[y][x];

    int ret0 = 0, ret1 = 0;
    vector<array<int, 3>> sorted_h, sorted_s;
    for(auto y = 0; y < r; ++y) {
        for(auto x = 0; x < c; ++x) {
            sorted_h.push_back({H[y][x], y, x}), sorted_s.push_back({S[y][x], y, x});
            if(S[y][x] < H[y][x]) ret0++;
        }
    }
    sort(sorted_h.begin(), sorted_h.end());
    reverse(sorted_h.begin(), sorted_h.end());
    sort(sorted_s.begin(), sorted_s.end());
    reverse(sorted_s.begin(), sorted_s.end());

    int n = sorted_h.size();
    DisjointSet ds(n);
    int dy[4] = {-1, 0, 0, 1};
    int dx[4] = {0, -1, 1, 0};
    auto opened = vector<vector<bool>>(r, vector<bool>(c));
    auto open = [&](auto y, auto x) {
        auto key = y * c + x;
        for(auto i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(!opened[ny][nx]) continue;
            auto nkey = ny * c + nx;
            ds.merge(key, nkey);
        }
        opened[y][x] = true;
    };

    for(int i = 0, j = 0, k = 0; i < n; i = j) {
        int s = sorted_s[i][0];
        while(j < n && sorted_s[j][0] == s) ++j;
        while(k < n && sorted_h[k][0] > s) {
            open(sorted_h[k][1], sorted_h[k][2]);
            ++k;
        }

        for(auto l = i; l < j; ++l) {
            int y = sorted_s[l][1], x = sorted_s[l][2];
            if(!opened[y][x]) continue;
            auto key = y * c + x;
            if(!ds.is_count(key))
                ds.set_count(key), ret1++;
        }
    }

    cout << ret0 << " " << ret1 << endl;
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
