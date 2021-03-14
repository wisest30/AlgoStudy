#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int u, v;
    cin >> u >> v;

    if(u > v) {
        cout << "NO" << endl;
        return;
    }

    int uc = 0, vc = 0;
    for(auto i = 0; i < 30; ++i) {
        if(u & 1 << i) uc++;
        if(v & 1 << i) vc++;
        if(uc < vc) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
