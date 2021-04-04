#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int x, y;
string s;
vector<vector<int>> dp;

int recur(int i, int prev) {
    if(i == s.size())
        return 0;
    
    auto& ret = dp[i][prev];
    if(ret != -1) return ret;

    if(s[i] == 'C')
        ret = recur(i+1, 0) + (prev == 1 ? y:0);
    else if(s[i] == 'J')
        ret = recur(i+1, 1) + (prev == 0 ? x:0);
    else {
        ret = min(recur(i+1, 0) + (prev == 1 ? y:0),
                recur(i+1, 1) + (prev == 0 ? x:0));
    }

    return ret;
}

void solve(int TestCase) {
    cin >> x >> y;
    cin >> s;
    dp = vector<vector<int>>(s.size(), vector<int>(3, -1));

    auto ret = recur(0, 2);
    cout << ret << endl;
}
 
int main() {
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
