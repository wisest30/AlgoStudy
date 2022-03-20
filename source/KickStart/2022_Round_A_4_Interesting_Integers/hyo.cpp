#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

long long dp[13][130][130][130];
long long recur(int n, int p, int s, int t) {
    if(n == 0)
        return s == t && p % t == 0;
    
    auto& ret = dp[n][p][s][t];
    if(ret != -1)
        return ret;

    ret = 0;
    for(auto d = 0; d <= 9; ++d)
        ret += recur(n - 1, p * d % t, s + d, t);

    return ret;
}

long long count(long long x) {
    auto str = to_string(x);
    int n = str.size();
    long long ret = 0;

    for(auto t = 1; t < 130; ++t) {
        int p = 1, s = 0;
        for(auto i = 0; i < n; ++i) {
            for(auto d = 0; d + '0' < str[i]; ++d) {
                if(i == 0 && d == 0)
                    continue;

                ret += recur(n - i - 1, p * d % t, s + d, t);
            }

            p *= str[i] - '0';
            p %= t;
            s += str[i] - '0';
        }

        for(auto i = 1; i < n; ++i)
            for(auto d = 1; d <= 9; ++d)
                ret += recur(i-1, d, d, t);
    }

    return ret;
}

void solve(int TestCase) {
    long long a, b;
    cin >> a >> b;

    auto ret = count(b + 1) - count(a);
    cout << ret << "\n";
}

int main(){
    memset(dp, -1, sizeof(dp));

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
