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
        if(r == 0 || n == r) return 1;
        else if(r > n) return 0;

        return fact[n] * pow_mod(fact[n-r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
    }
};

// 0C0 1C0 2C0 3C0 ... (a0)C0
// 1C1 2C1 3C1 4C1 ... (a1+1)C1
// 2C2 3C2 4C2 5C2 ... (a2+2)C2
// 3C3 4C3 5C3 6C3 ... (a3+3)C3

// (a0+0)C1
// (a1+1)C2
// (a2+2)C3
// (a3+3)C4

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n+1);
    for(auto& x : A) cin >> x;

    constexpr int MOD = 1e9 + 7;
    Combination2 comb(500000, MOD);
    ll ret = 0;
    for(auto i = 0; i <= n; ++i) {
        ret += comb.nCr(A[i] + i, i + 1);
        ret %= MOD;
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
