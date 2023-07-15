#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;

    auto max_val = max(d12, max(d23, d31));
    if(max_val == 1) {
        cout << "NO\n";
        return;
    }

    int u, v, x, uv, ux, vx;
    if(max_val == d12) u = 0, v = 1, x = 2, uv = d12, ux = d31, vx = d23;
    else if(max_val == d23) u = 1, v = 2, x = 0, uv = d23, ux = d12, vx = d31;
    else u = 2, v = 0, x = 1, uv = d31, ux = d23, vx = d12;

    if(ux + vx < uv) {
        cout << "NO\n";
        return;
    }

    if((ux + vx - uv) % 2) {
        cout << "NO\n";
        return;
    }

    auto need_node = uv + 1 + (ux + vx - uv) / 2;
    if(need_node > n) {
        cout << "NO\n";
        return;
    }

    vector<vector<int>> g(n);
    int prev = u, cur = 0, edge_cnt = n - 1;
    auto add_edge = [&](auto u, auto v) {
        g[u].push_back(v);
        edge_cnt--;
    };
    for(auto i = 0; i < uv-1; ++i) {
        if(ux + vx == uv &&  i + 1 == ux) {
            add_edge(prev, x);
            prev = x;
            continue;
        }

        while(cur == u || cur == v || cur == x) cur++;
        add_edge(prev, cur);
        prev = cur++;
    }
    add_edge(prev, v);

    if(ux + vx - uv) {
        prev = u;
        for(auto i = 0; i < ux - (ux + vx - uv) / 2; ++i) {
            prev = g[prev][0];
        }

        for(auto i = 0; i < (ux + vx - uv) / 2 - 1; ++i) {
            while(cur == u || cur == v || cur == x) cur++;
            add_edge(prev, cur);
            prev = cur++;
        }
        add_edge(prev, x);
    }

    while(edge_cnt) {
        while(cur == u || cur == v || cur == x) cur++;
        add_edge(u, cur++);
    }

    cout << "YES\n";
    for(auto i = 0; i < n; ++i) {
        for(auto j : g[i]) {
            cout << (i + 1) << " " << (j + 1) << "\n";
        }
    }
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
