#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 1e9+7;

ll pow_(ll a, ll b) {
    if(b == 0) return 1;
    else if(b % 2 == 0) return pow_(a * a % MOD, b / 2);
    else return a * pow_(a, b - 1) % MOD;
}

void solve(int TestCase) {
    ll n;
    cin >> n;

    // P[i] : a + b == i 이고 gcd(a, b) = 1 인 (a, b)쌍의 개수
    vector<ll> P(n+1);
    for(ll i = 2; i <= n; ++i)
        P[i] = i-1;
    for(ll i = 2; i <= n; ++i) {
        for(ll g = 2; g * g <= i; ++g) {
            if(i % g == 0) {
                P[i] -= P[i / g];
                if(g * g != i)
                    P[i] -= P[g];
            }
        }
    }

    ll ret = 0;
    for(ll a = 1; a <= n - 2; ++a) {
        ll k = n - a;
        for(ll g = 1; g * g <= k; ++g) {
            if(k % g == 0) {
                ll add = a * g % MOD * P[k / g] % MOD 
                        * pow_(__gcd(a, g), MOD-2) % MOD;
                ret = (ret + add) % MOD;

                if(g * g != k) {
                    ll p = k / g;
                    ll add = a * p % MOD * P[k / p] % MOD 
                            * pow_(__gcd(a, p), MOD-2) % MOD;
                    ret = (ret + add) % MOD;
                }
            }
        }
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
