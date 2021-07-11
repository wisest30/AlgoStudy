#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    int type;
    ll x;
};

void solve(int TestCase) {
    ll n, c;
    cin >> n >> c;

    vector<Point> A;
    for(auto i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        l++;

        if(l == r) continue;

        Point t0, t1;
        t0.type = 0;
        t0.x = l;
        t1.type = 1;
        t1.x = r;

        A.push_back(t0);
        A.push_back(t1);
    }

    sort(A.begin(), A.end(), [](auto& l, auto& r) {
        if(l.x == r.x)
            return l.type > r.type;

        return l.x < r.x;
    });

    vector<pair<ll, ll>> cnts;
    ll open_cnt = 0;
    Point last_p;
    last_p.x = last_p.type = -1;
    for(auto& p : A) {
        if(last_p.x != p.x && last_p.x != -1) {
            cnts.push_back({open_cnt, p.x - last_p.x});
        }

        if(p.type == 0) {
            open_cnt++;
        }
        else {
            open_cnt--;
        }

        last_p = p;
    }

    ll ret = n;
    sort(cnts.begin(), cnts.end());
    while(!cnts.empty() && c) {
        auto [cnt, d] = cnts.back();
        cnts.pop_back();

        auto cc = min(c, d);
        c -= cc;

        ret += cnt * cc;
    }

    cout << ret << endl;
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
