#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll r;
    cin >> r;

    ll cnt = 0;
    for(ll x = -r; x <= r; ++x) {
        ll a = 0, b = r + 1;
        while(a + 1 < b) {
            ll y = (a + b) / 2;
            if(round(sqrt(x * x + y * y)) <= r)
                a = y;
            else
                b = y;
        }

        cnt += 2 * a + 1;
    }

    ll cnt_wrong = 4 * r + 1;
    for(ll p = 2; p <= r; ++p) {
        ll a = 1, b = p;
        while(a + 1 < b) {
            ll x = (a + b) / 2;
            ll y = round(sqrt(p * p - x * x));
            if(y > x)
                a = x;
            else
                b = x;
        }

        cnt_wrong += a * 8;

        if(b == round(sqrt(p * p - b * b)))
            cnt_wrong += 4;
    }

    cout << (cnt - cnt_wrong) << endl;
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

