#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    auto check = [&](auto m) {
        auto B = A;
        auto kk = k;
        for(auto i = 0; i < n; ++i) if(B[i] * 2 < m) B[i] = 1000000000, --kk;
        if(kk < 0) return false;
        if(kk >= 2) return true;
        for(auto i = 0; i < n-1; ++i) {
            if(min(B[i], B[i+1]) >= m) return true;
            else if(max(B[i], B[i+1]) >= m && kk >= 1) return true;
        }
        return false;
    };

    auto l = 0, r = 1000000000 + 1;
    while(l + 1 < r) {
        auto m = (l + r) / 2;
        if(check(m)) l = m;
        else r = m;
    }

    cout << l << endl;
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
