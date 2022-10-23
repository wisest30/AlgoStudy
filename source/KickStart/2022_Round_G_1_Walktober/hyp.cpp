#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(int TestCase) {
    int m, n, p;
    cin >> m >> n >> p;

    auto A = vector<vector<int>>(m, vector<int>(n));
    for(auto& a : A) for(auto& x : a) cin >> x;

    auto max_col = vector<int>(n);
    for(auto i = 0; i < m; ++i) for(auto j = 0; j < n; ++j) max_col[j] = max(max_col[j], A[i][j]);

    auto ret = 0;
    for(auto i = 0; i < n; ++i) ret += max(0, max_col[i] - A[p-1][i]);
    cout << ret << endl;
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
