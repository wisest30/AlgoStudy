#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll n, c;
    cin >> n >> c;

    map<ll, ll> mp;
    for(auto i = 0; i < n; ++i) {
        ll c, d, h;
        cin >> c >> d >> h;

        if(d * h > mp[c])
            mp[c] = d * h;
    }
    
    vector<ll> max_dh(c + 1);
    for(auto& p : mp) {
        for(auto i = p.first; i <= c; i += p.first)
            max_dh[i] = max(max_dh[i], i / p.first * p.second);
    }
    for(auto i = 1; i <= c; ++i)
        max_dh[i] = max(max_dh[i], max_dh[i-1]);

    ll m;
    cin >> m;
    vector<ll> ret;
    for(auto i = 0; i < m; ++i) {
        ll d, h, dh;
        cin >> d >> h;
        dh = d * h;

        auto p = upper_bound(max_dh.begin(), max_dh.end(), dh);
        if(p == max_dh.end())
            ret.push_back(-1);
        else
            ret.push_back(p - max_dh.begin());
    }

    for(auto r : ret)
        cout << r << " ";
    cout << endl;
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
