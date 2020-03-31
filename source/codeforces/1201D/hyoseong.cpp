#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    auto T = vector<vector<int>>(n);
    for(auto i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        T[r].push_back(c);
    }
    for(auto& t : T)
        sort(t.begin(), t.end());
    while(T.back().empty()) {
        T.pop_back();
        n--;
    }
    auto safe = vector<int>(q);
    for(auto& c : safe) {
        cin >> c;
        c--;
    }
    sort(safe.begin(), safe.end());
    auto min_distance = [&](int x, int y) {
        int r = lower_bound(safe.begin(), safe.end(), x) - safe.begin();
        int l = r - 1;

        auto ret = numeric_limits<int>::max();
        if(l >= 0)
            ret = min(ret, abs(x - safe[l]) + abs(y - safe[l]) + 1);
        if(r < safe.size())
            ret = min(ret, abs(x - safe[r]) + abs(y - safe[r]) + 1);
        
        return ret;
    };

    auto p = vector<int>(2);
    auto val = vector<long long>(2);
    if(!T[0].empty()) {
        p[0] = p[1] = T[0].back();
        val[0] = val[1] = T[0].back();
    }

    for(auto i = 0; i < n - 1; ++i) {
        if(T[i+1].empty()) {
            val[0]++, val[1]++;
            continue;
        }
        
        auto nxt_p = vector<int>{T[i+1][0], T[i+1].back()};
        auto nxt_val = vector<long long>(2, numeric_limits<long long>::max());
        for(auto j = 0; j < 2; ++j) {
            nxt_val[0] = min(nxt_val[0], val[j] + nxt_p[1] - nxt_p[0] + min_distance(p[j], nxt_p[1]));
            nxt_val[1] = min(nxt_val[1], val[j] + nxt_p[1] - nxt_p[0] + min_distance(p[j], nxt_p[0]));
        }

        p = nxt_p;
        val = nxt_val;
    }

    cout << min(val[0], val[1]) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    int t;
//    cin >> t;
//    while(t--)
        solve();
}