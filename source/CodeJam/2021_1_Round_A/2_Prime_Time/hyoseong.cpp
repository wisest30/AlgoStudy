#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<ll> A(500);
    ll su = 0;
    for(auto i = 0; i < n; ++i) {
        ll pi, ni;
        cin >> pi >> ni;
        A[pi] = ni;
        su += pi * ni;
    }

    for(auto ret = su; ret > max(su - 30000, 2ll); --ret) {
        auto x = ret;
        bool fail = false;
        ll cur_sum = su;
        for(auto i = 2; i < 500; ++i) {
            int cnt = 0;
            while(x % i == 0) {
                x /= i;
                cnt++;
                cur_sum -= i;
            }

            if(cnt > A[i]) {
                fail = true;
                break;
            }
        }

        if(x != 1 || ret != cur_sum)
            fail = true;

        if(!fail) {
            cout << ret << endl;
            return;
        }
    }

    cout << 0 << endl;
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
