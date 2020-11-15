#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 100010;
ll n, X[MAX_N], Y[MAX_N], A[MAX_N];

ll f(ll x) {
    ll ret = 0;
    for(auto i = 0; i < n; ++i)
        ret += abs(x - A[i]);
    return ret;
}

void solve(int TestCase) {
    cin >> n;
    for(auto i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }
    
    sort(X, X + n);
    sort(Y, Y + n);

    ll ret = 0;        
    for(auto i = 0; i < n; ++i)
        ret += abs(Y[n / 2] - Y[i]);
    
    for(auto i = 0; i < n; ++i)
        A[i] = X[i] - i;
    
    ll l = -3 * 1000000000ll, r = 3 * 1000000000ll;
    while(r - l >= 3) {
        ll p = (l * 2 + r) / 3, q = (l + r * 2) / 3;
        if(f(p) <= f(q)) r = q;
        else l = p;
    }

    ll min_val = numeric_limits<ll>::max();
    for(auto i = l; i <= r; ++i) min_val = min(min_val, f(i));

    ret += min_val;
    cout << ret << endl;
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
