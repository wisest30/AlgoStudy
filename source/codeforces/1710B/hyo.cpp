#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class SimpleSegTree {
public :
    int n;
    vector<ll> T;
    SimpleSegTree(int n)
    : n(n), T(4 * n + 20, INT64_MIN) {}

    void set(int i, int l, int r, long long val, int idx) {
        if(r <= idx || idx < l) return;
        if(l+1 == r) { T[i] = val; return; }
        auto m = (l+r)/2;
        set(i*2+1, l, m, val, idx);
        set(i*2+2, m, r, val, idx);
        T[i] = max(T[i*2+1], T[i*2+2]);
    }
    long long get(int i, int l, int r, int L, int R) {
        if(L <= l && r <= R) return T[i];
        auto m = (l+r)/2;
        auto ret = INT64_MIN;
        if(L < m) ret = max(ret, get(i*2+1, l, m, L, R));
        if(R > m) ret = max(ret, get(i*2+2, m, r, L, R));
        return ret;
    }
    void set(long long val, int idx) { set(0, 0, n, val, idx); }
    long long get(int L, int R) { return get(0, 0, n, L, R); }
};

void solve(int TestCase) {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> A(n);
    for(auto& x : A) cin >> x.first >> x.second;

    map<ll, ll> d2, d1, d0;
    for(auto& p : A) {
        d2[p.first - p.second]++;
        d2[p.first] -= 2;
        d2[p.first + p.second]++;
    }

    ll px = INT64_MIN, pv = INT64_MIN;
    for(auto& p : d2) {
        d1[p.first] = px == INT64_MIN ? 0 : pv + d1[px];
        px = p.first, pv = p.second;
    }

    px = INT64_MIN;
    for(auto& p : d1)  {
        d0[p.first] = px == INT64_MIN ? 0 : p.second * (p.first - px) + d0[px];
        px = p.first;
    }

    SimpleSegTree st0(d0.size()), st1(d0.size()), st2(d0.size());
    int i = 0;
    map<ll, int> x_idx;
    for(auto& p : d0) {         
        st0.set(p.second, i);
        st1.set(p.second - p.first, i);
        st2.set(p.second + p.first, i);
        x_idx[p.first] = i++;
    }

    string ret;
    for(auto i = 0; i < n; ++i) {
        auto x0 = A[i].first - A[i].second;
        auto x1 = A[i].first;
        auto x2 = A[i].first + A[i].second;

        auto candi0 = st0.get(0, x_idx[x0]);
        auto candi1 = st1.get(x_idx[x0], x_idx[x1]) + x0;
        auto candi2 = st2.get(x_idx[x1], x_idx[x2]) - x2;
        auto candi3 = st0.get(x_idx[x2], d0.size());

        auto max_v = max(max(candi0, candi1), max(candi2, candi3));
        if(max_v > m) ret.push_back('0');
        else ret.push_back('1');
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
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
