#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    // k * p + p * (p - 1) / 2 = g

    ll g;
    cin >> g;

    int ret = 0;
    for(ll p = 1;;++p) {
        ll k = (g - p * (p - 1) / 2) / p;
        if(k <= 0) break;

        if((g - p * (p - 1) / 2) % p == 0)
            ret++;
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
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
