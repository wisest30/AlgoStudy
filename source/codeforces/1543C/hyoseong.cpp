#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const double eps = 1e-9;
map<pair<double, double>, double> dp;
double v;
double recur(double c, double m) {
    if(c <= eps && m <= eps)
        return 1.0;
    
    auto key = make_pair(c, m);
    if(dp.count(key))
        return dp[key];

    auto& ret = dp[key];

    if(c <= eps) ret = m * recur(c, max(0.0, m - v)) + 1.0;
    else if(m <= eps) ret = c * recur(max(0.0, c - v), m) + 1.0;
    else {
        double nxt_c = max(0.0, c - v);
        double nxt_m = max(0.0, m - v);
        ret = c * recur(nxt_c, m + (c - nxt_c) / 2)
            + m * recur(c + (m - nxt_m) / 2, nxt_m)
            + 1.0;
    }

    return ret;
}

void solve(int TestCase) {
    dp.clear();

    double c, m, p;
    cin >> c >> m >> p >> v;

    auto ret = recur(c, m);

    cout.precision(15);
    cout << fixed;
    cout << ret << endl;
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
