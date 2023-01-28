#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class PSum {
    using T = long long;
    vector<T> ps;

public :
    PSum() = default;

    template<typename U>
    PSum(const vector<U>& A)
    : ps(A.size() + 1)
    {
        for(auto i = 1; i < ps.size(); ++i)
            ps[i] = ps[i-1] + A[i-1];
    }

    T get(int left, int right) {
        return ps[right] - ps[left];
    }
};

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

int n;
vector<ll> A, F_IV;
vector<vector<ll>> dp;
PSum ps;

ll recur(int i, int cnt) {
    if(i == n+1)
        return cnt == n / 2;
    else if(cnt > n / 2)
        return 0;
    else if(cnt == n / 2)
        return ps.get(i, n+1) == 0;

    auto& ret = dp[i][cnt];
    if(ret != -1) return ret;

    ret = recur(i+1, cnt);
    if(A[i] > 0) {
        ll r = ps.get(0, i);
        ll add = 0;
        if(cnt == 0) {
            if(n > 2)
                add = r * (r - 1) % MOD * A[i] % MOD * recur(i + 1, cnt + 1) % MOD;
            else
                add = r % MOD * A[i] % MOD * recur(i + 1, cnt + 1) % MOD;
        } else if(cnt == n / 2 - 1) {
            add = A[i] * recur(i + 1, cnt + 1) % MOD;
        } else {
            add = max(0ll, r - cnt * 2 - 1) * A[i] % MOD * recur(i + 1, cnt + 1) % MOD;
        }
        
        ret = (ret + add) % MOD;
    }

    return ret;
}

void solve(int TestCase) {
    cin >> n;

    A = vector<ll>(n+1);
    for(auto i = 0; i < n; ++i) {
        int x;
        cin >> x;
        A[x]++;
    }

    ps = PSum(A);

    dp = vector<vector<ll>>(n+1, vector<ll>(n+1, -1));

    auto ret = recur(0, 0);
    for(auto i = 0; i <= n; ++i) {
        if(A[i])
            ret = ret * F_IV[A[i]] % MOD;
    }

    cout << ret << "\n";
}
 
void init() {
    F_IV = vector<ll>(5001);
    ll cur = 1;
    for(auto i = 1; i <= 5000; ++i) {
        cur = cur * i % MOD;
        F_IV[i] = inv(cur);
    }
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
