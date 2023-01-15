#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll r = 0LL;
    ll res;
    for(int i=0; i<30; i++){
        cout << "? " << -r + (1LL<<(i)) << " " << -r + (1LL<<(i)) + (1LL<<(i+1)) << endl;
        cin >> res;
        if(res == (1LL<<(i+1)))
            r += (1LL<<i);
    }
    cout << "! " << r << endl;
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
