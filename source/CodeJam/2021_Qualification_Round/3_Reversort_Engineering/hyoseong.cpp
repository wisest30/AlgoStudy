#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, c;
    cin >> n >> c;

    int min_cost = 0, max_cost = 0;
    for(auto i = 1; i <= n - 1; ++i) {
        min_cost += 1;
        max_cost += n + 1 - i;
    }

    if(c < min_cost || c > max_cost) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> ret(n);
    iota(ret.begin(), ret.end(), 1);

    for(auto i = n - 1; i >= 1; --i) {
        if(c >= n) {
            reverse(ret.begin() + i - 1, ret.end());
            c -= n - i + 1;
        }
        else {
            reverse(ret.begin() + i - 1, ret.begin() + c);
            c = i - 1;
        }
    }

    for(auto x : ret) cout << x << " ";
    cout << endl;
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
