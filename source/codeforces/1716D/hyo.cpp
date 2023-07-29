#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
void solve(int TestCase) {
    ll n, k;
    cin >> n >> k;

    auto p = 1;
    while(p * (p-1) / 2 + p * k <= n) ++p;

    vector<ll> dp(n+1), ret(n+1);
    dp[0] = 1;
    for(auto i = 1; i * (i-1) / 2 + i * k <= n; ++i) {
        vector<ll> ndp(n+1);
        for(auto j = k+i-1; j <=n; ++j) {
            ndp[j] = dp[j - (k+i-1)];
            ndp[j] += ndp[j - (k+i-1)];
            ndp[j] %= MOD;

            ret[j] = (ret[j] + ndp[j]) % MOD;
        }
        swap(dp, ndp);
    }
    
    for(auto i = 1; i <= n; ++i)
        cout << ret[i] << " ";
    cout << endl;
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
