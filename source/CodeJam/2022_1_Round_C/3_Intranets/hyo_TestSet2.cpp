#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
vector<ll> fact;

void init() {
    fact = vector<ll>(1e6 + 1);
    fact[0] = 1;
    for(auto i = 1; i < fact.size(); ++i)
        fact[i] = fact[i-1] * i % MOD;
}

ll pow_mod(ll x, ll y) {
    auto ret=1ll;
    while (y) {
        if (y % 2)
            ret = ret * x % MOD;
        x =  x * x % MOD;
        y /= 2;
    }
    return ret;
}

ll inv(ll k) {
    return pow_mod(k, MOD - 2);
}

ll nCr(ll n, ll r) {
    return fact[n] * inv(fact[n-r]) % MOD * inv(fact[r]) % MOD;
}

void solve(int TestCase) {
    ll m, k;
    cin >> m >> k;

    m--, k--;

    ll p = pow_mod(2, m - 2 * k - 1) * nCr(m - 1, 2 * k) % MOD * nCr(2 * k, k) % MOD * inv(k + 1) % MOD;
    ll q = nCr(2 * m, m) * inv(m + 1) % MOD;
    ll ret = p * inv(q) % MOD;

    cout << ret << endl;
}
 
int main(){
    init();

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

