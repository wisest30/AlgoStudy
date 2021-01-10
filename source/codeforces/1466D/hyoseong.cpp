#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> W(n);
    for(auto& x : W) cin >> x;

    vector<int> degree(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        degree[u]++;
        degree[v]++;
    }

    vector<int> A;
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < degree[i] - 1; ++j)
            A.push_back(W[i]);
    
    sort(A.begin(), A.end());

    ll ret = 0;
    for(auto i = 0; i < n; ++i)
        ret += W[i];
    cout << ret << " ";
    
    for(auto i = 0; i < n-2; ++i) {
        ret += A.back();
        A.pop_back();
        cout << ret << " ";
    }
    cout << endl;
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
