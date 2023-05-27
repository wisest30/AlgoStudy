#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    vector<ll> ps(n+1);
    for(auto i = 0; i < n; ++i)
        ps[i+1] = ps[i] + A[i];

    vector<ll> B(n+1);
    for(auto i = 1; i <= n; ++i) {
        B[i] = B[i-1];
        ll over = (i - 1) * B[i-1] - ps[i-1];
        B[i] += max(0LL, (A[i-1] - over - B[i-1] + i - 1) / i);
    }

    int q;
    cin >> q;
    for(auto i = 0; i < q; ++i) {
        ll t;
        cin >> t;

        auto check = [&](ll m) {
            if(B[m] > t) return false;
            ll over = m * t - ps[m];
            ll remain = ps[n] - ps[m];

            return remain <= over;
        };

        if(!check(n)) {
            cout << -1 << endl;
            continue;
        }

        ll l = 0, r = n;
        while(l + 1 < r) {
            auto m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m;
        }

        cout << r << endl;
    }
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
