#include<bits/stdc++.h>
 
using namespace std;

int n, m;
int P[100000], H[100000];
vector<int> edges[100000];
bool ans;

pair<long long, long long> dfs(int cur, int par) {
    auto ret = make_pair(0ll, 0ll);
    for(auto nxt : edges[cur]) {
        if(nxt == par) continue;
        auto sub_ret = dfs(nxt, cur);
        ret.first += sub_ret.first;
        ret.second += sub_ret.second;
    }
    
    ret.second += P[cur];
    auto h = ret.first - ret.second;
    auto diff = H[cur] - h;
    if(diff >= 0 && diff % 2 == 0 && diff / 2 <= ret.second) {
        ret.first += diff / 2;
        ret.second -= diff / 2;
    }
    else {
        ans = false;
        ret.first = ret.second = 0;
    }

    return ret;
}

void solve(int TestCase) {
    ans = true;
    cin >> n >> m;
    for(auto i = 0; i < n; ++i) cin >> P[i];
    for(auto i = 0; i < n; ++i) cin >> H[i];
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, -1);
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    for(auto& e : edges) e.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
//        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
