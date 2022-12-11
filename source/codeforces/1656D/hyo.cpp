#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll n;
    cin >> n;

    ll p = 1, q = n;
    while(q % 2 == 0)
        p *= 2, q /= 2;
    
    auto su = [](__int128 k) {
        return k * (k + 1) / 2; // int64 can be overflowed.
    };

    if(q == 1) 
        cout << -1 << endl;
    else if(n >= su(p * 2))
        cout << (p * 2) << endl;
    else
        cout << q << endl;
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
