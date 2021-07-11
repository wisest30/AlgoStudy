#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    set<pair<ll, ll>> s;
    for(auto i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        s.insert({a, b});
    }

    vector<ll> ret;
    for(auto i = 0; i < m; ++i) {
        ll x;
        cin >> x;

        auto p = s.lower_bound({x, 0});
        ll left_candi = -1;
        if(p != s.begin()) {
            auto [l, r] = *prev(p);
            left_candi = min(r, x);
        }

        ll right_candi = -1;
        if(p != s.end()) {
            auto [l, r] = *p;
            right_candi = l;
        }

        if(right_candi == -1 || (left_candi != -1 && abs(left_candi - x) <= abs(right_candi - x))) {
            ret.push_back(left_candi);
            auto pp = prev(p);
            auto [l, r] = *pp;
            s.erase(pp);
            if(l <= left_candi - 1) s.insert({l, left_candi - 1});
            if(left_candi + 1 <= r) s.insert({left_candi + 1, r});
        }
        else {
            ret.push_back(right_candi);
            auto [l, r] = *p;
            s.erase(p);
            if(l <= right_candi - 1) s.insert({l, right_candi - 1});
            if(right_candi + 1 <= r) s.insert({right_candi + 1, r});
        }
    }

    for(auto x : ret) cout << x << " ";
    cout << endl;
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
