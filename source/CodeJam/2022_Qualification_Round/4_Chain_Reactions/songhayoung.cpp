#include <bits/stdc++.h>
using namespace std;

long long solve(int n, vector<int>& cost, vector<int>& adj) {
    vector<pair<long long,int>> chain(n + 1, make_pair(0, INT_MAX));

    long long res = 0;

    for(int i = n; i >= 1; i--) {
        auto [sum, mi] = chain[i];

        if(sum) res += sum - mi;

        int ncost = max(cost[i], mi == INT_MAX ? 0 : mi);
        
        chain[adj[i]].first += ncost;
        chain[adj[i]].second = min(chain[adj[i]].second, ncost);
    }

    return res + chain[0].first;
}

int main() {
    int tc;
    cin>>tc;
    for(int i = 1; i <= tc; i++) {
        int n;
        cin>>n;
        vector<int> cost(n + 1), adj(n + 1);
        for(int i = 1; i <= n;i++) cin>>cost[i];
        for(int i = 1; i <= n;i++) cin>>adj[i];
        cout<<"Case #"<<i<<": "<<solve(n, cost, adj)<<endl;
    }
    return 0;
}
