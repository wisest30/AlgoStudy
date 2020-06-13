#include<bits/stdc++.h>
 
using namespace std;

int n;
vector<long long> a, b, c;
vector<vector<int>> edges;

pair<long long, long long> dfs(int cur, int par, long long min_cost) {
    min_cost = min(min_cost, (long long)a[cur]);

    auto ret = make_pair(0ll, 0ll);
    if(b[cur] && !c[cur]) ret.first--;
    else if(!b[cur] && c[cur]) ret.first++;

    for(auto i = 0; i < edges[cur].size(); ++i)
    {
        auto nxt = edges[cur][i];
        if(nxt == par) continue;
        auto sub_ret = dfs(nxt, cur, min_cost);
        ret.second += sub_ret.second;
            
        auto del_cnt = 0ll;
        if(ret.first * sub_ret.first < 0)
            del_cnt = min(abs(ret.first), abs(sub_ret.first));
        
        if(del_cnt)
            ret.second += del_cnt * min_cost * 2;
        
        ret.first += sub_ret.first;
    }
    return ret;
}

void solve(int TestCase) {
    cin >> n;
    a = b = c = vector<long long>(n);
    for(auto i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    
    edges = vector<vector<int>>(n);
    for(auto i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    auto ret = dfs(0, -1, INT_MAX);
    if(ret.first != 0)
        cout << -1 << endl;
    else
        cout << ret.second << endl;
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
