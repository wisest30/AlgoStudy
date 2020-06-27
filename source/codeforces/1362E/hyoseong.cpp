#include<bits/stdc++.h>
 
using namespace std;
 
long long pow_mod(long long x, long long y, long long mod) {
    auto ret=1ll;
    while (y) {
        if (y % 2)
            ret = ret * x % mod;
        x =  x * x % mod;
        y /= 2;
    }
    return ret;
 
}
long long pow_mod(long long x, long long y) {
    auto ret=1ll;
    while (y) {
        if (y % 2)
            ret = ret * x;
        x =  x * x;
        y /= 2;
 
        if(ret > 1000000 || x > 1000000) return -1;
    }
    return ret;
}
 
void solve(int TestCase) {
    constexpr int MOD = 1e9+7;
    int n, p;
    cin >> n >> p;
    auto A = vector<int>(n);
    for(auto& x : A)
        cin >> x;
    
    if(p == 1) {
        cout << (n % 2) << endl;
        return;
    }
 
    sort(A.begin(), A.end(), greater<>());
 
    auto r = pair<long long, long long>{0, 0};
    bool too_big = false;
    int remain_idx = -1;
    for(auto i = 0; i < n; ++i) {
        if(r.first == 0) {
            r.first = 1;
            r.second = A[i];
        }
        else {
            if(r.second == A[i])
                r.first--;
            else {
                long long x = pow_mod(p, r.second - A[i]);
                if(x < 0)
                    too_big = true;
                if(r.first * x > n)
                    too_big = true;
                if(too_big) {
                    remain_idx = i;
                    break;
                }
                else {
                    r.first *= pow_mod(p, r.second - A[i], MOD);
                    r.second = A[i];
 
                    r.first--;
                }
            }
        }
    }
 
    long long ret = r.first * pow_mod(p, r.second, MOD) % MOD;
    if(remain_idx != -1)
        for(auto i = remain_idx; i < n; ++i)
            ret = (ret - pow_mod(p, A[i], MOD) + MOD) % MOD;
    
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
