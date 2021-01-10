#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_BIT = 60;
constexpr int MOD = 1e9 + 7;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    vector<int> cnt(MAX_BIT);
    for(auto a : A)
        for(auto x = 0; x < MAX_BIT; ++x)
            if((a >> x) & 1)
                cnt[x]++;

    vector<ll> and_sum(n);
    for(auto i = 0; i < A.size(); ++i)
        for(auto x = 0; x < MAX_BIT; ++x)
            if((A[i] >> x) & 1)
                and_sum[i] = (and_sum[i] + (1ll << x) % MOD * cnt[x] % MOD) % MOD;

    ll su = 0;
    for(auto a : A)
        su = (su + a % MOD) % MOD;

    ll ret = 0;
    for(auto j = 0; j < n; ++j) {
        auto left = and_sum[j];
        auto right = (n * (A[j] % MOD) % MOD + su - and_sum[j] + MOD) % MOD;
        ret = (ret + left * right) % MOD;
    }

    cout << ret << endl;
}
 
int main(){
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
