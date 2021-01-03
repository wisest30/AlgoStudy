#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    int bs = 0;
    for(auto i = 0; i < n; ++i) {
        cin >> A[i] >> B[i];
        bs += B[i];
    }

    vector<vector<int>> dp(100 * n + 1, vector<int>(n+1, -1));
    dp[0][0] = 0;

    for(auto i = 0; i < n; ++i) {
        for(auto c = (int)dp.size() - 1; c - A[i] >= 0; --c)
            for(auto k = n; k - 1 >= 0; --k)
                if(dp[c - A[i]][k-1] >= 0)
                    dp[c][k] = max(dp[c][k], dp[c - A[i]][k-1] + B[i]);
    }

    cout.precision(15);
    cout << fixed;
    for(auto k = 1; k <= n; ++k) {
        double ret = 0;
        for(auto c = 0; c < dp.size(); ++c)
            if(dp[c][k] >= 0)
                ret = max(ret, min((double)c, dp[c][k] / 2.0 + bs / 2.0));
        
        cout << ret << " ";
    }
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
