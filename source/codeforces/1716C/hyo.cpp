#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int m;
    cin >> m;

    vector<vector<ll>> A(2, vector<ll>(m));
    for(auto i = 0; i < 2; ++i)
        for(auto& x : A[i]) cin >> x;

    auto P = A, M = A;
    for(auto i = 0; i < m; ++i)
        for(auto j = 0; j < 2; ++j)
            P[j][i] += i, M[j][i] -= i;

    for(auto i = m-2; i >= 0; --i)
        for(auto j = 0; j < 2; ++j)
            P[j][i] = max(P[j][i], P[j][i+1]), M[j][i] = max(M[j][i], M[j][i+1]);

    vector<vector<ll>> C(2, vector<ll>(m));
    auto i = 0, j = 0;
    while(i < m) {
        int ni, nj;
        if(i % 2 == 0) {
            if(j == 0) ni = i, nj = 1;
            else ni = i + 1, nj = 1;
        } else {
            if(j == 0) ni = i + 1, nj = 0;
            else ni = i, nj = 0;
        }

        if(ni < m)
            C[nj][ni] = C[j][i] + max(0ll, A[nj][ni] - C[j][i]) + 1;
    
        i = ni, j = nj;
    }

    ll ret = max(C[0][m-1], C[1][m-1]);
    for(auto i = 0; i < m-1; ++i) {
        for(auto j = 0; j < 2; ++j) {
            if(i % 2 != j % 2) continue;
            auto move_cnt = (m - i) * 2 - 1;
            auto wait_time = max(0ll, max(M[j][i+1] + i + 1, P[j^1][i] - i + 1 - move_cnt) - C[j][i]);
            ret = min(ret, C[j][i] + wait_time + move_cnt);
        }
    }

    cout << ret << endl;
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
