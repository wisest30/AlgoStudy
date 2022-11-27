#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

struct Opt {
    ll e, t, p, i;
};

void solve(int TestCase) {
    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    auto O = vector<vector<Opt>>(n);
    for(auto i = 0; i < m; ++i) {
        ll e, t, p;
        cin >> e >> t >> p;
        e--;

        O[e].push_back({e, t, p, i});
    }

    auto dp = vector<vector<vector<ll>>>(n);
    auto choice = vector<vector<vector<ll>>>(n); // -1 : not cached, 0 : not select, 1 : select
    for(auto i = 0; i < n; ++i) {
        dp[i] = vector<vector<ll>>(O[i].size() + 1, vector<ll>(101, -1));
        choice[i] = vector<vector<ll>>(O[i].size() + 1, vector<ll>(101, -1));
    }

    constexpr ll inf = INT64_MAX;
    function<ll(ll, ll, ll)> recur_dp = [&](ll ai, ll oi, ll p) {
        if(p >= 100) return 0ll;
        else if(oi >= O[ai].size()) return inf;

        auto& ret = dp[ai][oi][p];
        auto& ch = choice[ai][oi][p];
        if(ret != -1) return ret;

        ret = recur_dp(ai, oi + 1, p);
        ch = 0;

        auto candi = recur_dp(ai, oi + 1, p + O[ai][oi].p);
        if(candi != inf && candi + O[ai][oi].t < ret) {
            ret = candi + O[ai][oi].t;
            ch = 1;
        }
        
        return ret;
    };

    vector<ll> ret;
    ll cur_time = 0;
    for(auto i = 0; i < n; ++i) {
        auto min_time = recur_dp(i, 0, 0);

        if(min_time == inf || cur_time + min_time > A[i]) {
            cout << -1 << endl;
            return;
        }

        cur_time += min_time;

        auto oi = 0, p = 0;
        while(p < 100) {
            if(choice[i][oi][p]) {
                ret.push_back(O[i][oi].i);
                p += O[i][oi].p;
            }

            oi++;
        }
    }

    cout << ret.size() << endl;
    for(auto& i : ret) cout << (i + 1) << " ";
    cout << endl;
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
