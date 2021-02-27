#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int N[4];
    for(auto i = 0; i < 4; ++i) cin >> N[i];

    auto A = vector<vector<pair<ll, int>>>(4, vector<pair<ll, int>>());
    for(auto i = 0; i < 4; ++i)
        A[i].resize(N[i]);
    for(auto i = 0; i < 4; ++i) {
        for(auto j = 0; j < A[i].size(); ++j) {
            cin >> A[i][j].first;
            A[i][j].second = j;
        }
    }

    for(auto i = 0; i < 3; ++i) {
        sort(A[i].begin(), A[i].end());
        vector<int> Con(A[i].size());
        for(auto j = 0; j < A[i].size(); ++j)
            Con[A[i][j].second] = j;

        int m;
        cin >> m;

        auto edges = vector<vector<int>>(A[i+1].size());
        for(auto j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            u = Con[u];
            edges[v].push_back(u);
        }
        for(auto& e : edges) sort(e.begin(), e.end());

        for(auto j = 0; j < A[i+1].size(); ++j) {
            if(edges[j].size() == A[i].size()) {
                A[i+1][j].first = INT_MAX;
                continue;
            }

            int p = edges[j].size();
            for(auto k = 0; k < edges[j].size(); ++k) {
                if(k != edges[j][k]) {
                    p = k;
                    break;
                }
            }

            A[i+1][j].first += A[i][p].first;
        }
    }

    sort(A[3].begin(), A[3].end());
    auto ret = A[3][0].first;
    if(ret >= INT_MAX) ret = -1;
    cout << ret << endl;
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
