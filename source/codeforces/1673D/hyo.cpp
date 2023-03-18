#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
void solve(int TestCase) {
    ll b, q, y;
    cin >> b >> q >> y;

    ll c, r, z;
    cin >> c >> r >> z;

    if(b > c || b + (y - 1) * q < c + (z - 1) * r || r % q || (c - b) % q) {
        cout << 0 << endl;
    } else if(b > c - r || b + (y - 1) * q < c + z * r) {
        cout << -1 << endl;
    } else {
        vector<ll> P;
        for(ll i = 1; i * i <= r; ++i) {
            if(r % i == 0) {
                P.push_back(i);
                if(i * i != r)
                    P.push_back(r / i);
            }
        }

        ll ret = 0;
        for(auto p : P) {
            ll g = __gcd(p, q);
            ll l = p * q / g;
            if(l != r) continue;

            ll cnt = r / p;
            ret = (ret + cnt * cnt % MOD) % MOD;
        }

        cout << ret << endl;
    }
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
