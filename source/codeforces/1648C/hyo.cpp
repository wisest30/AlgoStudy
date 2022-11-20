#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;
constexpr ll MAX_N = 200005;

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

long long inv(long long x) {
    return pow_mod(x, MOD - 2, MOD);
}

class FenwickTree {
public:
    int N;
    vector<long long> f;
    FenwickTree(int N) : N(N), f(vector<long long>(N+10)) {}
    void upd(int i, long long val) {
        assert(i >= 0 && i < N);
        for(; i < f.size(); i |= i+1) f[i] += val;
    }

    long long get(int i) {
        assert(i >= 0 && i <= N);
        if(i == 0) return 0;
        i--;

        long long ret = 0;
        for(; i >= 0; i = (i & (i+1)) - 1) ret += f[i];
        return ret;
    }
};

void solve(int TestCase) {
    ll n, m;
    cin >> n >> m;

    vector<ll> s(n), t(m);
    for(auto& x : s) cin >> x;
    for(auto& x : t) cin >> x;

    vector<ll> fact(MAX_N);
    fact[0] = 1;
    for(ll i = 1; i < fact.size(); ++i)
        fact[i] = fact[i-1] * i % MOD;

    FenwickTree ft(MAX_N);
    for(auto x : s) ft.upd(x, 1);

    ll ret = 0, p = 1;
    for(auto i = 0; i < min(n, m); ++i) {
        ll add = p;
        add = add * ft.get(t[i]) % MOD;
        add = add * fact[n - i - 1] % MOD;
        ret = (ret + add) % MOD;

        auto cnt = ft.get(t[i] + 1) - ft.get(t[i]);
        if(cnt) {
            ft.upd(t[i], -1);
            p = p * cnt % MOD;
        }
        else
            break;
        
        if(i == n - 1 && n < m)
            ret = (ret + p) % MOD;
    }    

    map<int, int> counter;
    for(auto x : s) 
        ret = ret * inv(++counter[x]) % MOD;

    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    // cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
