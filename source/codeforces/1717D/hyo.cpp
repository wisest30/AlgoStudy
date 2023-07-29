#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class Combination2 {
    using T = unsigned long long;
    T MOD;
    vector<T> fact;
public :
    Combination2(int n, T MOD = 0)
    : MOD(MOD), fact(n+1) {
        fact[0] = 1;
        for(auto i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
    }

    T pow_mod(long long x, long long y, long long mod) {
        auto ret=1ll;
        while (y) {
                if (y % 2)
                    ret = ret * x % mod;
                x =  x * x % mod;
                y /= 2;
            }
        return ret;
    }

    T nCr(int n, int r) {
        return fact[n] * pow_mod(fact[n-r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
    }
};

constexpr int MOD = 1e9+7;
void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    Combination2 comb(n, MOD);
    ll ret = 1;
    for(auto i = 0; i < n; ++i)
        ret = ret * 2 % MOD;
    for(auto i = 0; i < n-k; ++i)
        ret = (ret - comb.nCr(n, i) + MOD) % MOD;
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
