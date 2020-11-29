#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr long long MOD = 998244353;
constexpr int MAX_N = 2 * 100000 + 1;
ll n, cache[MAX_N];

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

long long f(ll x) {
    return pow_mod(x, MOD - 2, MOD) % MOD;
}

ll dp(int x) {
    if(x == 0) return 0;
    if(x == 1) return f(2);

    auto& ret = cache[x];
    if(ret != -1) return ret;

    ret = dp(x-2) * f(4) % MOD;
    ret += dp(x-1) * f(2) % MOD;
    ret %= MOD;
    return ret;
}

void solve(int TestCase) {
    memset(cache, -1, sizeof(cache));

    cin >> n;
    auto ret = dp(n);
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
