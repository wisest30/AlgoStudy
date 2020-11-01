#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a > b * c)
        cout << -1 << endl;
    else {
        auto k = a / (b * d) + 1;
        auto ret = a * k - k * (k - 1) / 2 * b * d;
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
 
