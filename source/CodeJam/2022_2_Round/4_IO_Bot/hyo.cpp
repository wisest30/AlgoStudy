#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

ll solve2(vector<pair<ll, int>>& A, ll c) {
    int n = A.size();

    sort(A.begin(), A.end());

    vector<ll> ps0(n+1), ps1(n+1);
    for(auto i = 1; i <= n; ++i) {
        ps0[i] = ps0[i-1], ps1[i] = ps1[i-1];
        if(A[i-1].second == 0)
            ps0[i] += A[i-1].first;
        else
            ps1[i] += A[i-1].first;
    }

    unordered_map<int, int> m;
    m[0] = 0;
    int cnt0 = 0, cnt1 = 0;
    vector<ll> dp(n+1);
    for(auto i = 1; i <= n; ++i) {
        ll x = A[i-1].first;
        int t = A[i-1].second;

        t ? cnt1++ : cnt0++;
        auto diff_cnt = cnt0 - cnt1;

        dp[i] = dp[i-1] + 2 * x;
        if(i > 1) {
            if(t != A[i-2].second)
                dp[i] = dp[i-2] + 2 * x;
            else {
                dp[i] = min(dp[i], dp[i-2] + 2 * x + c);
                if(m.count(diff_cnt)) {
                    int k = m[diff_cnt];
                    ll s = t ? ps1[i] - ps1[k] : ps0[i] - ps0[k];
                    dp[i] = min(dp[i], dp[k] + 2 * s);
                }
            }
        }
        m[diff_cnt] = i;
    }

    return dp[n];
}

void solve(int TestCase) {
    ll n, c;
    cin >> n >> c;

    vector<pair<ll, int>> A, B;
    for(auto i = 0; i < n; ++i) {
        ll x;
        int t;
        cin >> x >> t;
        if(x < 0) A.push_back({-x, t});
        else B.push_back({x, t});
    }

    ll ret = solve2(A, c) + solve2(B, c);
    cout << ret << endl;
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
