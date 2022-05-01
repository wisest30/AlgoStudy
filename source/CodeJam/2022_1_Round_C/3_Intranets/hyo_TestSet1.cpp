#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
long long m, k;
long long dp[51][51][51 * 51];
long long pow_mod(long long x, long long y) {
    auto ret=1ll;
    while (y) {
        if (y % 2) ret = ret * x % MOD;
        x =  x * x % MOD;
        y /= 2;
    }
    return ret;
}

long long inv(long long x) {
    return pow_mod(x, MOD - 2);
}

// connected node cnt, group cnt, remain edge count
long long recur(long long ccnt, long long gcnt, long long remain) {
    if(remain == 0) {
        if(ccnt == m && gcnt == k)
            return 1;
        else
            return 0;
    }

    auto& ret = dp[ccnt][gcnt][remain];
    if(ret != -1)
        return ret;

    ret = 0;
    if(ccnt + 2 <= m && gcnt + 1 <= k) {
        ret += (m - ccnt) * (m - ccnt - 1) / 2 * recur(ccnt + 2, gcnt + 1, remain - 1) % MOD;
        ret %= MOD;
    }
    
    if(ccnt >= 1 && ccnt + 1 <= m) {
        ret += ccnt * (m - ccnt) * recur(ccnt + 1, gcnt, remain - 1) % MOD;
        ret %= MOD;
    }

    if(ccnt >= 2) {
        long long c = ccnt * (ccnt - 1) / 2 - (m * (m - 1) / 2 - remain);
        ret += c * recur(ccnt, gcnt, remain - 1);
        ret %= MOD;
    }

    return ret;
}

void solve(int TestCase) {
    cin >> m >> k;
    if(m > 50) {
        // it's small test set version.
        exit(0);
    }

    memset(dp, -1, sizeof(dp));

    long long fact = 1;
    for(auto i = 1ll; i <= m * (m - 1) / 2; ++i)
        fact = fact * i % MOD;
    
    auto ret = recur(0, 0, m * (m - 1) / 2);
    ret = ret * inv(fact) % MOD;

    cout << ret << endl;

    memset(dp, -1, sizeof(dp));
    m = 3, k = 1;
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

