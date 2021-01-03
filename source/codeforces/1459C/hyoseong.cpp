#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;


void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<ll> A(n), B(m);
    for(auto& a : A) cin >> a;
    for(auto& b : B) cin >> b;

    if(n == 1) {
        for(auto b : B) cout << (A[0] + b) << endl;
    }
    else {
        sort(A.begin(), A.end());
        ll g = A[1] - A[0];
        for(auto i = 1; i < n; ++i)
            g = __gcd(g, A[i] - A[0]);

        for(auto i = 0; i < m; ++i)
            cout << __gcd(A[0] + B[i], g) << " ";
        cout << endl;
    }
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
