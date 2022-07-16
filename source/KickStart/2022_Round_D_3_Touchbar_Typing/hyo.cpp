#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for(auto& x : A) cin >> x;
    cin >> m;
    vector<int> B(m);
    for(auto& x : B) cin >> x;

    vector<vector<int>> P(2501);
    for(auto i = 0; i < B.size(); ++i)
        P[B[i]].push_back(i);

    auto dp = vector<int>(P[A[0]].size());
    for(auto i = 1; i < A.size(); ++i) {
        auto ndp = vector<int>(P[A[i]].size(), INT_MAX);
        for(auto j = 0; j < ndp.size(); ++j) {
            auto& p = P[A[i-1]];
            auto k = lower_bound(p.begin(), p.end(), P[A[i]][j]) - p.begin();
            if(k < p.size())
                ndp[j] = min(ndp[j], dp[k] + abs(P[A[i]][j] - p[k]));
            if(k - 1 >= 0)
                ndp[j] = min(ndp[j], dp[k-1] + abs(P[A[i]][j] - p[k-1]));
        }

        swap(dp, ndp);
    }

    auto ret = *min_element(dp.begin(), dp.end());

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
