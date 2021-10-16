#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, a;
    cin >> n >> a;

    vector<pair<int, int>> ret;
    if(a < n-2) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(auto i = 0; i < n / 2; ++i)
        ret.push_back({i, i / 2 + 1});

    if(n % 2)
        ret.push_back({n / 2, 10000});

    for(auto i = n / 2 - 1; i >= 0; --i)
        ret.push_back({i, i / 2});

    auto r = a - (n-2);
    if(r > 0)
        ret[0].second += r;

    cout << "POSSIBLE\n";
    for(auto& p : ret)
        cout << p.first << " " << p.second << "\n";
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
