#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    // ai, ci
    vector<array<ll, 2>> A(n);
    for(auto& x : A)
        cin >> x[0] >> x[1];

    sort(A.begin(), A.end());

    ll ret = 0, par = A[0][0];
    for(auto& x : A) {
        ret += max(0ll, x[0] - par) + x[1];
        par = max(par, x[0] + x[1]);
    }
    
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
