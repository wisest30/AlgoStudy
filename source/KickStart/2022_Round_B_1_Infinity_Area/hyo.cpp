#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    const double pi = 3.14159265358979323846;
    ll r, a, b;
    cin >> r >> a >> b;

    double ret = r * r * pi;
    while(r > 0) {
        r *= a;
        ret += r * r * pi;
        r /= b;
        ret += r * r * pi;
    }

    cout << fixed;
    cout.precision(16);
    cout << ret << "\n";
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

