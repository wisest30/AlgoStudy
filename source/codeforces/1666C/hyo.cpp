#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    vector<pair<ll, ll>> A(3);
    for(auto& a : A) cin >> a.first >> a.second;

    sort(A.begin(), A.end());

    vector<array<ll, 4>> ret;
    auto max_y = max(A[0].second, max(A[1].second, A[2].second));
    auto min_y = min(A[0].second, min(A[1].second, A[2].second));
    ret.push_back({A[1].first, min_y, A[1].first, max_y});
    ret.push_back({A[0].first, A[0].second, A[1].first, A[0].second});
    ret.push_back({A[1].first, A[2].second, A[2].first, A[2].second});
    
    cout << ret.size() << endl;
    for(auto& x : ret) cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
