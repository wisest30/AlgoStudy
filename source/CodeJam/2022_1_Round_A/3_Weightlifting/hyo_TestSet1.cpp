#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int e, w;
vector<vector<int>> A, dp;

int recur(int l, int r) {
    if(l + 1 == r)
        return 2 * accumulate(A[l].begin(), A[l].end(), 0);
    
    auto& ret = dp[l][r];
    if(ret != -1)
        return ret;
    
    vector<int> minv(w, INT_MAX);
    for(auto i = l; i < r; ++i)
        for(auto j = 0; j < w; ++j)
            minv[j] = min(minv[j], A[i][j]);
    auto su = accumulate(minv.begin(), minv.end(), 0);

    ret = INT_MAX;
    for(auto i = l + 1; i < r; ++i) {
        auto sub_ret0 = recur(l, i);
        auto sub_ret1 = recur(i, r);

        ret = min(ret, sub_ret0 + sub_ret1 - 2 * su);
    }

    return ret;
}

void solve(int TestCase) {
    cin >> e >> w;

    A = vector<vector<int>>(e, vector<int>(w));
    for(auto& arr : A)
        for(auto& x : arr)
            cin >> x;

    dp = vector<vector<int>>(e, vector<int>(e + 1, -1));
    auto ret = recur(0, e);
    cout << ret << "\n";
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
