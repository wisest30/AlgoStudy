#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int INVALID = -1000000;
vector<vector<int>> D;
map<long long, int> dp;

int recur(int prev, int n) {
    if(n == 0) return 0;

    ll key = 1234567ll * prev + n;
    if(dp.count(key)) return dp[key];

    auto& ret = dp[key];
    for(auto d : D[n]) {
        if(d <= prev) continue;
        if(d % prev != 0) continue;

        auto nxt_n = n - d;
        if(nxt_n != 0 && nxt_n < d) continue;
        if(nxt_n % d != 0) continue;
        ret = max(ret, recur(d, nxt_n) + 1);
    }

    return ret;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    auto ret = recur(1, n);
    cout << ret << '\n';
}

void init() {
    constexpr int MAX_N = 1e6 + 1;
    //constexpr int MAX_N = 100;
    D.resize(MAX_N);
    for(auto i = 3; i < MAX_N; ++i) {
        for(auto j = i; j < MAX_N; j += i) {
            D[j].push_back(i);
        }
    }
}

int main(){
    init();
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
