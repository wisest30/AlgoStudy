#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    const ll mod = 1e9 + 7;

    auto input = [&](auto n) {
        ll sx = 0, ssx = 0, sy = 0, ssy = 0;
        for(auto i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            sx = (sx + x) % mod;
            ssx = (ssx + x * x % mod) % mod;
            sy = (sy + y) % mod;
            ssy = (ssy + y * y % mod) % mod;
        }

        return tuple<ll, ll, ll, ll>(sx, ssx, sy, ssy);
    };

    int n, m;
    cin >> n;
    auto [sax, ssax, say, ssay] = input(n);
    cin >> m;
    auto [sbx, ssbx, sby, ssby] = input(m);

    ll ans = (ssax * m % mod + (mod - 2 * sax * sbx % mod) + ssbx * n % mod) % mod;
    ans += (ssay * m % mod + (mod - 2 * say * sby % mod) + ssby * n % mod) % mod;
    ans %= mod;

    cout << ans << endl;
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