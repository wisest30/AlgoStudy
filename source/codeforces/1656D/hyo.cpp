#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
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

constexpr int MAX_N = 200000;
vector<vector<ll>> factors;
void init() {
    vector<ll> min_factor = vector<long long>(MAX_N + 1);
    iota(min_factor.begin(), min_factor.end(), 0);
    for(ll i = 2; i * i <= MAX_N; ++i)
        if(min_factor[i] == i)
            for(ll j = i * i; j <= MAX_N; j += i)
                if(min_factor[j] == j)
                    min_factor[j] = i;
    
    factors.resize(MAX_N + 1);
    for(ll i = 1; i <= MAX_N; ++i) {
        auto x = i;
        while(x > 1) {
            factors[i].push_back(min_factor[x]);
            x /= min_factor[x];
        }
    }
}

void solve(int TestCase) {
    int n;
    cin >> n;

    auto g = vector<vector<array<int, 3>>>(n);
    for(auto i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--, v--;

        auto gd = __gcd(x, y);
        x /= gd, y /= gd;

        g[u].push_back({v, x, y});
        g[v].push_back({u, y, x});
    }

    ll val_cur = 1, val_sum = 1;
    unordered_map<ll, ll> f, min_f;
    function<void(int, int, int, int)> dfs = [&](auto cur, auto prev, auto x, auto y) {
        if(prev != -1) {
            for(auto p : factors[x])
                min_f[p] = min(min_f[p], --f[p]);
            for(auto p : factors[y])
                min_f[p] = min(min_f[p], ++f[p]);
            val_cur = val_cur * inv(x) % MOD * y % MOD;
            val_sum = (val_sum + val_cur) % MOD;
        }

        for(auto& e : g[cur]) {
            if(e[0] == prev) continue;
            dfs(e[0], cur, e[1], e[2]);
        }

        if(prev != -1) {
            for(auto p : factors[x])
                f[p]++;
            for(auto p : factors[y])
                f[p]--;
            val_cur = val_cur * x % MOD * inv(y) % MOD;
        }
    };

    dfs(0, -1, -1, -1);

    auto ret = val_sum;
    for(auto& p : min_f) {
        if(p.second < 0) {
            for(auto i = 0; i < -p.second; ++i)
                ret = ret * p.first % MOD;
        }
    }

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
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
