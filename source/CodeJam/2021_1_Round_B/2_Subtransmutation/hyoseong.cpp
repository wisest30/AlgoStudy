#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

#include<bits/stdc++.h>
 
using namespace std;

constexpr int MAX_V = 10000;
void solve(int TestCase) {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    auto is_possible = [&](auto k) {
        vector<int> P(k + 1);
        P[k] = 1;

        for(auto i = k; i >= 0; --i) {
            if(i < n && P[i] < A[i]) return false;
            if(i < n) P[i] -= A[i];
    
            if(i - a >= 0) P[i-a] = min(MAX_V, P[i-a] + P[i]);
            if(i - b >= 0) P[i-b] = min(MAX_V, P[i-b] + P[i]);
        }

        return true;
    };

    auto ret = -1;
    for(auto i = 1000; i >= n; --i) {
        if(is_possible(i))
            ret = i + 1;
    }

    if(ret == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ret << endl;
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
