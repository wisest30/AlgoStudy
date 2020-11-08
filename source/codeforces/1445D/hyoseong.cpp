#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
constexpr int MAX_N = 300000 + 10;
ll n, A[MAX_N * 2];
long long fact[MAX_N];
void init_fact() {
    fact[0] = 1;
    for(auto i = 1; i < MAX_N; ++i)
        fact[i] = fact[i-1] * i % MOD;
}

long long pow_mod(long long x, long long y, long long mod) {
    auto ret=1ll;
    while (y) {
            if (y % 2)
                ret = ret * x % mod;
            x =  x * x % mod;
            y /= 2;
        }
    return ret;
}

long long nCr(int n, int r) {
    return fact[n] * pow_mod(fact[n-r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
}

void solve(int TestCase) {
    init_fact();

    cin >> n;
    for(auto i = 0; i < 2 * n; ++i) cin >> A[i];

    sort(A, A + 2 * n);

    ll s1 = 0, s2 = 0;
    for(auto i = 0; i < n; ++i) s1 += A[i];
    for(auto i = n; i < 2 * n; ++i) s2 += A[i];
    ll p = (s2 - s1) % MOD;

    ll ret = p * nCr(2 * n, n) % MOD;
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
