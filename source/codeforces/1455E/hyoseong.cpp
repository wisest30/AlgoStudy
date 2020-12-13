#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int n = 4;
ll X[n], Y[n], XX[n], YY[n];

ll solve3(ll x, ll y) {
    ll A[4];
    A[0] = XX[1] - x;
    A[1] = XX[3] - x;
    A[2] = YY[2] - y;
    A[3] = YY[3] - y;

    sort(A, A + 4);
    ll len = A[2];//max(1ll, A[2]);

    ll ret = 0;
    ret += abs(XX[0] - x) + abs(YY[0] - y);
    ret += abs(XX[1] - x - len) + abs(YY[1] - y);
    ret += abs(XX[2] - x) + abs(YY[2] - y - len);
    ret += abs(XX[3] - x - len) + abs(YY[3] - y - len);
    return ret;
}

ll solve2(ll x, ll y) {
    ll ret = numeric_limits<ll>::max();
    int p[4] = {0, 1, 2, 3};
    do {
        for(auto i = 0; i < 4; ++i)
            XX[i] = X[p[i]], YY[i] = Y[p[i]];
        
        ret = min(ret, solve3(x, y));
    } while(next_permutation(p, p + 4));
    return ret;
}

void solve(int TestCase) {
    for(auto i = 0; i < n; ++i)
        cin >> X[i] >> Y[i];
    
    ll ret = numeric_limits<ll>::max();
    for(auto i = 0; i < 4; ++i)
        for(auto j = 0; j < 4; ++j)
            ret = min(ret, solve2(X[i], Y[j]));
    
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
