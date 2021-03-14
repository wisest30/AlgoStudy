#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    ll ret = 0;
    vector<ll> free(n);

    for(auto i = 0; i < n; ++i) {
        ret += max(0ll, A[i] - 1 - free[i]);
        for(auto j = i+2; j <= min((ll)n-1, A[i] + i); ++j)
            free[j]++;
        
        if(i < n-1)
            free[i+1] += max(0ll, free[i] - (A[i] - 1));
    }

    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
       // cout << "Case #"<< i << ": ";
        solve(i);
    }
}
