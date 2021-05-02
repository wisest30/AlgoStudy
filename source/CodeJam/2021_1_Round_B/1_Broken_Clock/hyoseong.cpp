#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

#include<bits/stdc++.h>
 
using namespace std;

constexpr ll Full = 43200000000000;

bool in_range(ll l, ll m, ll r) {
    if(r < l) r += Full;
    if(m < l) m += Full;
    return l <= m && m < r;
}

ll diff(ll l, ll r) {
    if(r < l) r += Full;
    return r - l;
}

vector<ll> f(ll a, ll b, ll c) {
    ll constexpr ten9 = 1000000000;
    auto ret = vector<ll>(4, -1);
    b = (b - a + Full) % Full;
    c = (c - a + Full) % Full;
    a = 0;

    for(ll h = 0; h < 12; ++h) {
        for(ll m = 0; m < 60; ++m) {
            for(ll s = 0; s < 60; ++s) {
                ll cur_second = h * 3600 + m * 60 + s;
                ll pa = (cur_second * ten9) % Full;
                ll na = (pa + ten9) % Full;
                ll pb = (cur_second * ten9 * 12) % Full;
                ll nb = (pb + ten9 * 12) % Full;
                ll pc = (cur_second * ten9 * 720) % Full;
                ll nc = (pc + ten9 * 720) % Full;

                if(!in_range((pb - pa + Full) % Full, b, (nb - na + Full) % Full)) continue;
                if(!in_range((pc - pa + Full) % Full, c, (nc - na + Full) % Full)) continue;

                auto x = diff((pb - pa + Full) % Full, b);
                auto y = diff((pc - pa + Full) % Full, c);

                if(x % 11) continue;
                if(y % 719) continue;

                return {h, m, s, x / 11};
            }
        }
    }

    return ret;
}

void solve(int TestCase) {
    long long a, b, c;
    cin >> a >> b >> c;

    if(a == b && b == c) {
        cout << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
        return;
    }

    vector<ll> ret;
    auto ans = [&]() {
        if(ret[0] != -1) {
            cout << ret[0] << " " << ret[1] << " " << ret[2] << " " << ret[3] << endl;
            return true;
        }

        return false;
    };

    ret = f(a, b, c);
    if(ans()) return;
    ret = f(a, c, b);
    if(ans()) return;
    ret = f(b, a, c);
    if(ans()) return;
    ret = f(b, c, a);
    if(ans()) return;
    ret = f(c, a, b);
    if(ans()) return;
    ret = f(c, b, a);
    if(ans()) return;

    cout << "error" << endl; 
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
