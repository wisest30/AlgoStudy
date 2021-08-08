#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, max_remove_cnt;
vector<int> A;
vector<vector<int>> dp;

int recur(int i, int removed) {
    if(i == n) return 0;
    
    auto& ret = dp[i][removed];
    if(ret != -1) return ret;

    ret = recur(i + 1, removed) + (A[i] == i - removed);
    if(removed < max_remove_cnt)
        ret = max(ret, recur(i + 1, removed + 1));
    
    return ret;
}

void solve(int TestCase) {
    cin >> n >> k;
    A.resize(n);
    for(auto& x : A) {
        cin >> x;
        x--;
    }

    auto check = [&](long long m) {
        dp = vector<vector<int>>(n, vector<int>(m+1, -1));
        max_remove_cnt = m;
        auto max_good_cnt = recur(0, 0);
        return max_good_cnt >= k;
    };

    long long l = -1, r = n+1;
    while(l + 1 < r) {
        long long m = (l+r) / 2;
        if(check(m))
            r = m;
        else
            l = m;
    }

    auto ret = r <= n ? r : -1;
    cout << ret << endl;
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
