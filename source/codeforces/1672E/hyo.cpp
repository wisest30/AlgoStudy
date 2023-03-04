#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int quest(int x) {
    cout << "? " << x << endl;
    int ret;
    cin >> ret;
    return ret;
}

void ans(int x) {
    cout << "! " << x << endl;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    auto check = [&](long long m) {
        return quest(m) == 1;
    };

    long long l = 0, r = 5000000;
    while(l + 1 < r) {
        long long m = (l+r) / 2;
        if(check(m))
            r = m;
        else
            l = m;
    }

    ll ret = r;
    for(ll h = 2; h <= n; ++h) {
        ll candi = quest(r / h) * (r / h);
        if(candi)
            ret = min(ret, candi);
    }

    ans(ret);
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
