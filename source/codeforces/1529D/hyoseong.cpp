#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    constexpr int MOD = 998244353;

    int n;
    cin >> n;
    
    vector<int> F(n+1);
    for(auto i = 1; i <= n; ++i)
        for(auto j = i; j <= n; j += i)
            F[j]++;
    
    int64_t a = 0, s = 0;
    for(auto i = 1; i <= n; ++i) {
        if(i == 1) a = 1;
        else a = (F[i] + s) % MOD;
        s = (s + a) % MOD;
    }

    cout << a << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
//        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
