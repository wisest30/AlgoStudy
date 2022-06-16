#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

ll f(vector<pair<ll, int>>& A, ll c) {
    sort(A.begin(), A.end());

    vector<ll> I, O;
    for(auto& p : A) {
        if(p.second == 0) O.push_back(p.first);
        else I.push_back(p.first);
    }

    auto dp = vector<vector<ll>>(O.size() + 1, vector<ll>(I.size() + 1, INT64_MAX));
    dp[O.size()][I.size()] = 0;
    for(auto i = (int)O.size(); i >= 0; --i) {
        for(auto j = (int)I.size(); j >= 0; --j) {
            if(i > 0 && j > 0) dp[i-1][j-1] = min(dp[i-1][j-1], dp[i][j] + 2 * max(O[i-1], I[j-1]));
            if(i > 0) dp[i-1][j] = min(dp[i-1][j], dp[i][j] + 2 * O[i-1]);
            if(i > 1) dp[i-2][j] = min(dp[i-2][j], dp[i][j] + 2 * O[i-1] + c);
            if(j > 0) dp[i][j-1] = min(dp[i][j-1], dp[i][j] + 2 * I[j-1]);
            if(j > 1) dp[i][j-2] = min(dp[i][j-2], dp[i][j] + 2 * I[j-1] + c);
        }
    }

    return dp[0][0];
}

void solve(int TestCase) {
    ll n, c;
    cin >> n >> c;

    // only TestSet1
    if(n > 5000)
        exit(0);

    vector<pair<ll, int>> A, B;
    for(auto i = 0; i < n; ++i) {
        pair<ll, int> p;
        cin >> p.first >> p.second;
        if(p.first > 0) A.push_back(p);
        else B.push_back({-p.first, p.second});
    }

    ll ret = f(A, c) + f(B, c);
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
