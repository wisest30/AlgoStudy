#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
long long pow_mod(long long x, long long y) {
    auto ret=1ll;
    while (y) {
            if (y % 2)
                ret = ret * x % MOD;
            x =  x * x % MOD;
            y /= 2;
        }
    return ret;
}

long long inv(long long x) {
    return pow_mod(x, MOD - 2);
}

class Combination2 {
    using T = unsigned long long;
    vector<T> fact;
public :
    Combination2(int n)
    : fact(n+1) {
        fact[0] = 1;
        for(auto i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
    }

    T nCr(int n, int r) {
        return fact[n] * inv(fact[n-r]) % MOD * inv(fact[r]) % MOD;
    }
};

int n;
string s;
ll dp[401][401][401];
ll recur(int l, int r, int len) {
    if(len <= 0) return 0;
    if(l >= r) return 0;
    if(l + 1 == r) return len == 1;

    auto& ret = dp[l][r][len];
    if(ret != -1) return ret;

    ret = recur(l + 1, r, len)
        + recur(l, r - 1, len)
        + MOD - recur(l + 1, r - 1, len);

    if(s[l] == s[r-1])
        ret += recur(l + 1, r - 1, len - 2) + (len == 2);

    ret %= MOD;
    return ret;
}

bool is_pal(const string& s) {
    for(auto i = 0; i < s.size() / 2; ++i)
        if(s[i] != s[(int)s.size() - i - 1])
            return false;

    return true;
}

void solve(int TestCase) {
    cin >> n >> s;

    memset(dp, -1, sizeof(dp));

    Combination2 comb(n);
    ll ret = 1;
    for(auto len = 1; len <= n; ++len)
        ret = (ret + recur(0, n, len) * inv(comb.nCr(n, len)) % MOD) % MOD;

    if(is_pal(s))
        ret = (ret - 1 + MOD) % MOD;

    cout << ret << endl;
}

int main(){
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
