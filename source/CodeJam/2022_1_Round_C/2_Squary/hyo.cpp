#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    long long s = 0, s2 = 0;
    for(auto i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        s += x, s2 += x * x;
    }

    if(k == 1) {
        if(s == 0) {
            if(s2 != 0) cout << "IMPOSSIBLE" << endl;
            else cout << 1 << endl;
            return;
        }
        long long x = (s2 - s * s) / s;
        if(x % 2 == 1) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        x /= 2;
        cout << x << endl;
    } else {
        long long x = 1 - s;
        long long y = (s2 - s * s - 2 * s * x) / 2;
        cout << x << " " << y << endl;
    }
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