#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<ll> A(n+1);
    A[0] = 1;
    for(auto i = 1; i < A.size(); ++i)
        A[i] = A[i-1] * k % MOD;

    ll ret = 0;
    int p = (n + 1) / 2;
    for(auto i = 0; i < p; ++i)
        ret = (ret + (s[i] - 'a') * A[p - (i + 1)] % MOD) % MOD;

    auto t = s;
    for(int i = p; i < n; ++i)
        t[i] = t[n - 1 - i];

    if(t < s)
        ret = (ret + 1) % MOD;

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
