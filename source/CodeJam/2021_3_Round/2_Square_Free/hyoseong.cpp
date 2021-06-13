#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int r, c;
vector<int> R, C;

struct edge {
    int from, to, f, c;
};

vector<edge> edges;
vector<vector<int>> G;

bool dfs(int cur, vector<bool>& visited) {
    auto n = r + c;
    if(cur == n+1)
        return true;
    if(visited[cur])
        return false;
    
    visited[cur] = true;
    for(auto& eIdx : G[cur]) {
        auto& e = edges[eIdx];
        if(e.from == cur) {
            if(e.f < e.c) {
                e.f++;
                if(dfs(e.to, visited))
                    return true;
                e.f--;
            }
        } else {
            if(e.f > 0) {
                e.f--;
                if(dfs(e.from, visited))
                    return true;
                e.f++;
            }
        }
    }

    return false;
}

vector<string> getOne() {
    int n = r + c;
    G = vector<vector<int>>(n + 2);
    edges.clear();
    for(auto u = 0; u < r; ++u) {
        for(auto v = r; v < n; ++v) {
            edge e{u, v, 0, 1};
            G[u].push_back(edges.size());
            G[v].push_back(edges.size());
            edges.push_back(e);
        }
    }

    for(auto i = 0; i < r; ++i) {
        edge e{n, i, 0, R[i]};
        G[n].push_back(edges.size());
        G[i].push_back(edges.size());
        edges.push_back(e);
    }

    for(auto i = r; i < n; ++i) {
        edge e{i, n+1, 0, C[i - r]};
        G[i].push_back(edges.size());
        G[n+1].push_back(edges.size());
        edges.push_back(e);
    }

   while(true) {
        auto visited = vector<bool>(n+2);
        if(!dfs(n, visited))
            break;
    }

    vector<string> ret(r, string(c, '\\'));
    for(auto& e : edges) {
        if(e.from >= n || e.to >= n)
            continue;
        if(e.f == 0)
            continue;
        ret[e.from][e.to - r] = '/';
    }

    vector<int> RR(r), CC(c);
    for(auto i = 0; i < r; ++i)
        for(auto j = 0; j < c; ++j)
            if(ret[i][j] == '/')
                RR[i]++, CC[j]++;

    if(RR != R || CC != C)
        return {};

    return ret;
}

void convert(vector<string>& ret) {
    auto process = [&](auto y, auto x) {
        auto p = -1;
        for(auto i = y+1; i < r; ++i)
            if(ret[i][x] == '\\' && ret[i][x+1] == '/')
                p = i;

        if(p == -1)
            return false;
        
        swap(ret[y][x], ret[y][x+1]);
        swap(ret[p][x], ret[p][x+1]);

        return true;
    };

    while(true) {
        auto conti = false;
        for(auto y = 0; y < r; ++y) {
            for(auto x = 0; x < c-1; ++x)
                if(ret[y][x] == '/' && ret[y][x+1] == '\\' && process(y, x))
                    conti = true;
        }
        if(!conti)
            break;
    }
}

void solve(int TestCase) {
    cin >> r >> c;

    R.resize(r), C.resize(c);
    for(auto& x : R) cin >> x;
    for(auto& x : C) cin >> x;

    auto ret = getOne();
    if(ret.empty()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    convert(ret);

    cout << "POSSIBLE" << endl;
    for(auto& x : ret)
        cout << x << endl;
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
