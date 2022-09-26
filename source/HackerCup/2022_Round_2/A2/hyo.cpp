#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
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
    vector<long long> f_sum, f_mul;
    FenwickTree(int N) : N(N), f_sum(vector<long long>(N+10)), f_mul(vector<long long>(N+10, 1)) {}
    void upd(int idx, long long val) {
        assert(idx >= 0 && idx < N);
        for(auto i = idx; i < f_sum.size(); i |= i+1) f_sum[i] += val;

        if(val > 0)
            for(auto i = idx; i < f_mul.size(); i |= i+1) f_mul[i] = f_mul[i] * val % MOD;
        else {
            ll iv = inv(abs(val));
            for(auto i = idx; i < f_mul.size(); i |= i+1) f_mul[i] = f_mul[i] * iv % MOD;
        }
    }

    long long get_sum(int i) {
        assert(i >= 0 && i <= N);
        if(i == 0) return 0;
        i--;

        long long ret = 0;
        for(; i >= 0; i = (i & (i+1)) - 1) ret += f_sum[i];
        return ret;
    }

    long long get_mul(int i) {
        assert(i >= 0 && i <= N);
        if(i == 0) return 1;
        i--;

        long long ret = 1;
        for(; i >= 0; i = (i & (i+1)) - 1) ret = ret * f_mul[i] % MOD;
        return ret;
    }

    long long get_sum(int l, int r) {
        assert(l >= 0 && l <= N);
        assert(r >= 0 && r <= N);
        return get_sum(r) - get_sum(l);
    }

    long long get_mul(int l, int r) {
        assert(l >= 0 && l <= N);
        assert(r >= 0 && r <= N);
        return get_mul(r) * inv(get_mul(l)) % MOD;
    }
};

auto random_address = []{char *pt = new char;delete pt;return uint64_t(pt);};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);
vector<ll> R(3000000);
void init() {
    for(auto& x : R) x = rng() % MOD;
    R.erase(unique(R.begin(), R.end()), R.end());
    assert(R.size() > 1000000);
}

void solve(int TestCase) {
    int n;
    cin >> n;

    unordered_map<ll, ll> rmap;
    FenwickTree ft(n);
    for(auto i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        x = R[x];
        ft.upd(i, x);
    }

    int q, ans = 0;
    cin >> q;
    for(auto i2 = 0; i2 < q; ++i2) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;

        if(t == 1) {
            ll old = ft.get_sum(l, l+1);
            ft.upd(l, -old);
            ft.upd(l, R[r]);
        } else {
            for(auto i = 0; i < 2; ++i) {
                auto m = (l + r) / 2 + i;
                auto d = i == 0 ? (ft.get_sum(m, r) - ft.get_sum(l, m)) : (ft.get_sum(l, m) - ft.get_sum(m, r));
                if(d <= 0) continue;

                auto d0 = ft.get_mul(l, m);
                auto d1 = ft.get_mul(m, r);
                if(i == 0 && d0 * d % MOD == d1 || i == 1 && d0 == d1 * d % MOD) {
                    ++ans;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}

