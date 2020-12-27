#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;

    k -= l;
    r -=  l;

    auto p = r - y;
    int cnt = 2e6 + 10;
    while(cnt--) {
        if(k <= p) {
            auto d = y - x;
            if(d < 0) {
                cout << (k / (-d) < t ? "No" : "Yes") << endl;
                return;
            }
            else if(d == 0) {
                cout << "Yes" << endl;
                return;
            }
            else {
                auto days = (p + 1 - k + d - 1) / d;
                days = min(days, t);

                k += days * d;
                t -= days;

                if(t == 0) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
        else {
            if(p < 0) {
                cout << (k / x < t ? "No" : "Yes") << endl;
                return;
            }
            else {
                auto days = (k - p + x - 1) / x;
                days = min(days, t);
                k -= days * x;
                t -= days;

                if(k < 0) {
                    cout << "No" << endl;
                    return;
                }
                if(t == 0) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }

    cout << "Yes" << endl;
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
