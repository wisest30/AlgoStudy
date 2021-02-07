#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    ll g = 0;
    for(auto i = 1; i < n; ++i)
        g = __gcd(g, A[i] - A[0]);
    
    cout << ((k - A[0]) % g ? "NO" : "YES") << endl;
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
