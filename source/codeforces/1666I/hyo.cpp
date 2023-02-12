#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n, m;

int dig(int r, int c) {
    cout << "DIG " << r << " " << c << endl;
    int x;
    cin >> x;
    return x;
}
int scan(int r, int c) {
    cout << "SCAN " << r << " " << c << endl;
    int x;
    cin >> x;
    return x;
}

// (1, 1) : x0 + y0 + x1 + y1 = d0 + 4
// (n, 1) : -x0 + y0 -x1 + y1 = d1 - 2n + 2
// x0 + x1 = (d0 - d1 + 2n + 2) / 2
// y0 + y1 = (d0 + d1 - 2n + 6) / 2

// p = (x0 + x1) / 2 = (d0 - d1 + 2n + 2) / 4
// (p, 1) : -x0 + y0 + x1 + y1 = d2 + 2
// -x0 + x1 = d2 + 2 - (d0 + d1 - 2n + 6) / 2
// x0 = (d0 - d2 + 2) / 2, x1 = (-d1 + d2 + 2n) / 2

// p = (y0 + y1) / 2 = (d0 + d1 - 2n + 6) / 4
// (1, p) : x0 - y0 + x1 + y1 = d3 + 2
// -y0 + y1 = d3 + 2 - (d0 - d1 + 2n + 2) / 2
// y0 = (d0 - d3 + 2) / 2, y1 = (d1 + d3 - 2n + 4) / 2

void solve(int TestCase) {
    cin >> n >> m;

    auto d0 = scan(1, 1);
    auto d1 = scan(n, 1);
    auto p = (d0 - d1 + 2 * n + 2) / 4;
    auto d2 = scan(p, 1);
    auto x0 =  (d0 - d2 + 2) / 2, x1 = (-d1 + d2 + 2 * n) / 2;

    p = (d0 + d1 - 2 * n + 6) / 4;
    auto  d3 = scan(1, p);
    auto y0 = (d0 - d3 + 2) / 2, y1 = (d1 + d3 - 2 * n + 4) / 2;

    auto res = dig(x0, y0);
    if(res) dig(x1, y1);
    else {
        dig(x0, y1);
        dig(x1, y0);
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
