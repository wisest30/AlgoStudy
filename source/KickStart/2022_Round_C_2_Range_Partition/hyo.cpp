#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll n, x, y;
    cin >> n >> x >> y;

    ll total_sum = n * (n + 1) / 2;
    if(total_sum * x % (x + y)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    ll s = total_sum * x / (x + y);
    vector<int> ret;
    for(auto i = n; i >= 1; --i) {
        if(s >= i) {
            s -= i;
            ret.push_back(i);
        }
    }

    if(s) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE\n";
        cout << ret.size() << "\n";
        for(auto r : ret) cout << r << " ";
        cout << endl;
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
