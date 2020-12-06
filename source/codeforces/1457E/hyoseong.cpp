#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 5e5 + 10;
ll n, k, A[MAX_N];
void solve(int TestCase) {
    cin >> n >> k;
    for(auto i = 0; i < n; ++i)
        cin >> A[i];
    
    sort(A, A+n, greater<ll>());

    priority_queue<ll> q;
    for(auto i = 0; i < k + 1; ++i)
        q.push(0);

    ll ret = 0;
    for(auto i = 0; i < n; ++i) {
        auto a = q.top(); q.pop();
        ret += a;
        a += A[i];
        q.push(a);
    }

    cout << ret << endl;
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
