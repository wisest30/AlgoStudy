#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll n, l;
    cin >> n >> l;

    vector<pair<ll, int>> L, R;
    for(auto i = 0; i < n; ++i) {
        ll p, d;
        cin >> p >> d;
        if(d == 0) L.push_back({p, i});
        else R.push_back({p, i});
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    vector<pair<ll, int>> drop_time;
    for(auto i = 0; i < R.size(); ++i) {
        auto p = R[i].first;
        int j = lower_bound(L.begin(), L.end(), make_pair(p, 0)) - L.begin();
        int l_cnt = i + 1;
        int r_cnt = (int)L.size() - j;
        if(r_cnt >= l_cnt) {
            auto k = j + l_cnt - 1;
            auto t = L[k].first;
            drop_time.push_back({t, R[i].second});
        } else {
            auto k = i - r_cnt;
            auto t = l - R[k].first;
            drop_time.push_back({t, R[i].second});
        }
    }

    for(auto i = 0; i < L.size(); ++i) {
        auto p = L[i].first;
        auto j = lower_bound(R.begin(), R.end(), make_pair(p, 0)) - R.begin();
        int l_cnt = j;
        int r_cnt = (int)L.size() - i;
        if(l_cnt >= r_cnt) {
            auto k = j - r_cnt;
            auto t = l - R[k].first;
            drop_time.push_back({t, L[i].second});
        } else {
            auto k = i + l_cnt;
            auto t = L[k].first;
            drop_time.push_back({t, L[i].second});
        }
    }

    sort(drop_time.begin(), drop_time.end());
    for(auto& p : drop_time) cout << (p.second + 1) << " ";
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
