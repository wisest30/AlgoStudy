#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n;
string s;
vector<vector<int>> dp;

bool check(int x, int len) {
    vector<int> A;
    for(auto i = 0; i < 6; ++i)
        A.push_back((x & (1 << i)) ? 1 : 0);
    
    if(len >= 5 && A[0] == A[4] && A[1] == A[3]) return false;
    else if(len >= 6 && A[0] == A[5] && A[1] == A[4] && A[2] == A[3]) return false;
    else return true;
}

bool recur(int i, int prev) {
    if(i == n) return true;
    auto& ret = dp[i][prev];
    if(ret != -1) return ret;

    ret = false;
    int cur = (prev << 1) & 0b111111;
    if(s[i] == '0') {
        if(check(cur, i + 1))
            ret |= recur(i + 1, cur);
    } else if(s[i] == '1') {
        cur |= 1;
        if(check(cur, i + 1))
            ret |= recur(i + 1, cur);
    } else {
        if(check(cur, i + 1))
            ret |= recur(i + 1, cur);
        
        cur |= 1;
        if(check(cur, i + 1))
            ret |= recur(i + 1, cur);
    }

    return ret;
}

void solve(int TestCase) {
    cin >> n >> s;

    dp = vector<vector<int>>(n, vector<int>(64, -1));

    auto ret = recur(0, 0);
    if(ret) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
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
