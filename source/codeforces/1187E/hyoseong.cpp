#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    auto E = vector<vector<int>>(n);
    for(auto i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    auto ret = 0ll;
    auto Cnt = vector<int>(n);
    auto St = stack<int>{};
    auto Vis = vector<bool>(n);
    St.push(0);
    while(!St.empty()) {
        auto cur = St.top();
        if(Vis[cur]) {
            Cnt[cur] = 1;
            for(auto nxt : E[cur])
                Cnt[cur] += Cnt[nxt];
            ret += Cnt[cur];
            St.pop();
            continue;
        }

        Vis[cur] = true;
        for(auto nxt : E[cur]) {
            if(Vis[nxt])
                continue;
            St.push(nxt);
        }
    }

    Vis = vector<bool>(n, false);
    St.push(0);
    auto StRet = stack<long long>();
    StRet.push(ret);
    while(!St.empty()) {
        auto cur = St.top();
        auto cur_ret = StRet.top();
        St.pop(), StRet.pop();

        if(Vis[cur])
            continue;
        Vis[cur] = true;

        for(auto nxt : E[cur]) {
            if(Vis[nxt])
                continue;
            St.push(nxt);
            auto nxt_ret = cur_ret - Cnt[nxt] + (n - Cnt[nxt]);
            StRet.push(nxt_ret);
            ret = max(ret, nxt_ret);
        }
    }

    cout << ret << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    int t;
//    cin >> t;
//    while(t--)
        solve();
}
