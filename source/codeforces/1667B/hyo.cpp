#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class SimpleSegTree {
private :
    int n;
    vector<long long> T;

public :
    SimpleSegTree() = delete;
    SimpleSegTree(int n)
    : n(n), T(4 * n + 20, INT64_MIN)
    {/* init code */}

private :
    void put(int i, int l, int r, long long val, int idx)
    {
        if (r <= idx || idx < l) return;
        if (l+1 == r)
        {
            T[i] = val;
            return;
        }
        int m = (l + r) / 2;
        put(i * 2 + 1, l, m, val, idx);
        put(i * 2 + 2, m, r, val, idx);
        T[i] = max(T[i * 2 + 1], T[i * 2 + 2]);
    }
    long long get(int i, int l, int r, int L, int R)
    {
        if(L <= l && r <= R)
            return T[i];

        int m = (l + r) / 2;
        long long ret = INT64_MIN;
        if(L < m)
            ret = max(ret, get(i * 2 + 1, l, m, L, R));
        if(R > m)
            ret = max(ret, get(i * 2 + 2, m, r, L, R));

        return ret;
    }

public :
    void put(long long val, int idx) { put(0, 0, n, val, idx); }
    long long get(int L, int R) { return get(0, 0, n, L, R); }
};

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    vector<ll> ps(n+1);
    for(auto i = 0; i < n; ++i)
        ps[i+1] = ps[i] + A[i];

    auto sorted_ps = ps;
    sort(sorted_ps.begin(), sorted_ps.end());
    map<ll, int> idx_map;
    for(auto i = 0; i < sorted_ps.size(); ++i)
        idx_map[sorted_ps[i]] = i;
    
    vector<ll> dp(n+1);
    SimpleSegTree st(n+1);
    st.put(0, idx_map[0]);
    for(auto i = 0; i < n; ++i) {
        auto st_idx = idx_map[ps[i+1]];
        if(A[i] > 0) dp[i+1] = dp[i] + 1;
        else if(A[i] == 0) dp[i+1] = dp[i];
        else dp[i+1] = dp[i] - 1;

        if(st.get(0, st_idx) != INT64_MIN)
            dp[i+1] =  max(dp[i+1], st.get(0, st_idx) + i + 1);

        auto old_val = st.get(st_idx, st_idx+1);
        st.put(max(old_val, dp[i+1] - (i+1)), st_idx);
    }

    auto ret = dp[n];
    cout << ret << endl;
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
