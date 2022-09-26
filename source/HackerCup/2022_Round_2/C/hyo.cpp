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

ll I[9000001];

void init() {
    for(auto i = 1; i <= 9000000; ++i)
        I[i] = pow_mod(i, MOD - 2, MOD);
}

void solve(int TestCase) {
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> A(n);
    ll total_cnt = 0, less = 0, same = 0;
    for(auto i = 0; i < n; ++i) {
        auto& x = A[i];
        cin >> x.first >> x.second;
        total_cnt += x.first;
        if(x.second < A[0].second)
            less += x.first;
        else if(x.second == A[0].second)
            same += x.first;
    }
    same--;

    vector<ll> L(k+1), R(k+1);
    R[0] = L[0] = 1;
    for(auto i = 1; i <= k; ++i) {
        R[i] = R[i-1] * max(0ll, less - i + 1) % MOD;
        L[i] = L[i-1] * max(0ll, less + same - k + i) % MOD;
    }

    ll ans = 0;
    for(auto i = 0; i < k + 1; ++i) {
        ans += L[i] * R[k - i] % MOD;
        ans %= MOD;
    }
    for(auto i = 0; i < k + 1; ++i)
        ans = ans * I[total_cnt - i] % MOD;

    ans = ans * A[0].first % MOD;
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

