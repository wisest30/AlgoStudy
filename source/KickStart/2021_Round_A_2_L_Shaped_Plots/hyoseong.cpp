#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int r, c;
    cin >> r >> c;

    auto A = vector<vector<int>>(r, vector<int>(c));
    for(auto i = 0; i < r; ++i)
        for(auto j = 0; j < c; ++j)
            cin >> A[i][j];
    
    auto U = A;
    auto L = A;
    auto R = A;
    auto D = A;

    for(auto i = 0; i < r; ++i) {
        for(auto j = 0; j < c; ++j) {
            if(A[i][j] == 0) continue;
            if(i > 0) U[i][j] += U[i-1][j];
            if(j > 0) L[i][j] += L[i][j-1];
        }
    }

    for(auto i = r-1; i >= 0; --i) {
        for(auto j = c-1; j >= 0; --j) {
            if(A[i][j] == 0) continue;
            if(i < r - 1) D[i][j] += D[i+1][j];
            if(j < c - 1) R[i][j] += R[i][j+1];
        }
    }

    long long ret = 0;
    for(auto i = 0; i < r; ++i) {
        for(auto j = 0; j < c; ++j) {
            if(A[i][j] == 0) continue;
            int x;
            int add = 0;
            x = min(U[i][j], L[i][j] / 2);
            if(x > 1) add += x - 1;
            x = min(U[i][j], R[i][j] / 2);
            if(x > 1) add += x - 1;
            x = min(D[i][j], L[i][j] / 2);
            if(x > 1) add += x - 1;
            x = min(D[i][j], R[i][j] / 2);
            if(x > 1) add += x - 1;
            x = min(U[i][j] / 2, L[i][j]);
            if(x > 1) add += x - 1;
            x = min(D[i][j] / 2, L[i][j]);
            if(x > 1) add += x - 1;
            x = min(U[i][j] / 2, R[i][j]);
            if(x > 1) add += x - 1;
            x = min(D[i][j] / 2, R[i][j]);
            if(x > 1) add += x - 1;

            ret += add;
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
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
