#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    vector<int> n(3);
    for(auto& x : n) cin >> x;

    vector<vector<ll>> A(3);
    vector<ll> su(3), min_val(3, INT_MAX);
    for(auto i = 0; i < 3; ++i) {
        A[i].resize(n[i]);
        for(auto& x : A[i]) {
            cin >> x;
            su[i] += x;
            min_val[i] = min(min_val[i], x);
        }
    }

    ll ret = 0;
    ret = max(ret, su[0] + su[1] - su[2]);
    ret = max(ret, su[0] - su[1] + su[2]);
    ret = max(ret, -su[0] + su[1] + su[2]);
    ret = max(ret, su[0] + su[1] + su[2] - 2 * (min_val[0] + min_val[1]));
    ret = max(ret, su[0] + su[1] + su[2] - 2 * (min_val[0] + min_val[2]));
    ret = max(ret, su[0] + su[1] + su[2] - 2 * (min_val[1] + min_val[2]));

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
