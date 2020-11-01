#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 501;
int n, m, row[MAX_N * MAX_N], col[MAX_N * MAX_N], A[MAX_N][MAX_N];
void solve(int TestCase) {
    cin >> n >> m;
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < m; ++j) {
            int x;
            cin >> x;
            col[x] = j;
        }
    
    for(auto j = 0; j < m; ++j)
        for(auto i = 0; i < n; ++i) {
            int x;
            cin >> x;
            row[x] = i;
        }
    
    for(auto i = 1; i <= n * m; ++i)
        A[row[i]][col[i]] = i;
    
    for(auto i = 0; i < n; ++i) {
        for(auto j = 0; j < m; ++j) cout << A[i][j] << " ";
        cout << endl;
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
 
