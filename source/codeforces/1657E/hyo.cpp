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

constexpr int MOD = 998244353;

void solve(int TestCase) {
    Combination2 comb(250, MOD);

    ll n, k;
    cin >> n >> k;

    auto dp = vector<vector<ll>>(n, vector<ll>(k+1));
    fill(dp[0].begin(), dp[0].end(), 1);

    for(auto i = 1; i < n; ++i) {
        for(auto j = 1; j <= k; ++j) {
            for(auto p = 0; p <= i; ++p) {
                ll cnt =  p * (i - p);
                if(p >= 2)
                    cnt += comb.nCr(p, 2);
                ll add = dp[i - p][j - 1] * comb.nCr(n - 1 - (i - p), p) % MOD;
                add = add * comb.pow_mod(k - j + 1, cnt, MOD) % MOD;

                dp[i][j] = (dp[i][j] + add) % MOD;
            }
        }
    }

    cout << dp[n-1][k] << endl;
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
