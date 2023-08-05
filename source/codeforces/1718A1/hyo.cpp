#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 1e9+7;

void solve(int TestCase) {
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& x : A) cin >> x;

    vector<int> dp(n+1);
    map<int, int> xor_ps;
    xor_ps[0] = 0;
    auto x = 0;
    for(auto i = 1; i <= n; ++i) {
        x ^= A[i-1];
        dp[i] = dp[i-1] + 1;
        if(xor_ps.count(x))
            dp[i] = min(dp[i], dp[xor_ps[x]] + i - xor_ps[x] - 1);
    
        xor_ps[x] = i;
    }

    cout << dp.back() << endl;
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
