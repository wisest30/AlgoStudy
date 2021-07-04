#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n;
vector<int> Z, O;
vector<vector<int>> dp;
constexpr int inf = 1e8;

int recur(int i, int j) {
    if(j == O.size())
        return 0;
    if(i == Z.size())
        return inf;

    auto& ret = dp[i][j];
    if(ret != -1) return ret;

    ret = min(recur(i + 1, j), recur(i + 1, j + 1) + abs(Z[i] - O[j]));

    if(ret > inf)
        ret = inf;
    return ret;
}

void solve(int TestCase) {
    cin >> n;
    vector<int> A(n);
    for(auto& x : A) cin >> x;

    dp = vector<vector<int>>(n + 1, vector<int>(n+1, -1));

    for(auto i = 0; i < n; ++i)
        if(A[i]) O.push_back(i);
        else Z.push_back(i);
    
    auto ret = recur(0, 0);
    cout << ret << endl;
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
