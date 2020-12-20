#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n, answer;
vector<vector<int>> edges;

int dfs(int cur, int prev) {   
    vector<int> sub_rets;
    for(auto nxt : edges[cur]) {
        if(nxt == prev) continue;

        sub_rets.push_back(dfs(nxt, cur));
    }

    sort(sub_rets.begin(), sub_rets.end());

    int m = (int)sub_rets.size();
    if(m == 0)
        return 0;
    else if(m == 1) {
        answer = max(answer, sub_rets[0] + 1);
        return sub_rets[0] + 1;
    }
    else if(cur == 0) {
        answer = max(answer, sub_rets.back() + 1);
        answer = max(answer, sub_rets[m-2] + 2);
        return sub_rets[0] + 1;
    }
    else {
        answer = max(answer, sub_rets.back() + 2);
        return sub_rets[0] + 1;
    }
}

void solve(int TestCase) {
    cin >> n;
    edges = vector<vector<int>>(n);
    for(auto i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    answer = 0;
    dfs(0, -1);

    cout << answer << endl;
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
