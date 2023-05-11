#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class SimpleSegTree {
private :
    int n;
    vector<long long> T;

public :
    SimpleSegTree(int n)
    : n(n), T(4 * n + 20, INT_MAX)
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
        T[i] = min(T[i * 2 + 1], T[i * 2 + 2]);
    }
    long long get(int i, int l, int r, int L, int R)
    {
        if(L <= l && r <= R)
            return T[i];

        int m = (l + r) / 2;
        long long ret = INT_MAX;
        if(L < m)
            ret = min(ret, get(i * 2 + 1, l, m, L, R));
        if(R > m)
            ret = min(ret, get(i * 2 + 2, m, r, L, R));

        return ret;
    }

public :
    void put(long long val, int idx) { put(0, 0, n, val, idx); }
    long long get(int L, int R) { return get(0, 0, n, L, R); }
};

vector<pair<int, int>> get_max_range(const vector<ll>& A) {
    int n = A.size();
    auto ret = vector<pair<int, int>>(n);
    vector<ll> st;
    for(auto i = 0; i < n; ++i) {
        while(!st.empty() && A[st.back()] <= A[i]) {
            ret[st.back()].second = i;
            st.pop_back();
        }
        if(st.empty()) ret[i].first = 0;
        else ret[i].first = st.back() + 1;
        st.push_back(i);
    }
    while(!st.empty()) {
        ret[st.back()].second = n;
        st.pop_back();
    }

    return ret;
}

bool f(const vector<ll>& A) {
    int n = A.size();
    vector<ll> ps(n+1);
    for(auto i = 1; i <= n; ++i)
        ps[i] = ps[i-1] + A[i-1];

    SimpleSegTree st(n+1);
    for(auto i = 0; i <= n; ++i)
        st.put(ps[i], i);

    auto max_range = get_max_range(A);

    auto ret = true;
    for(auto i = 0; i < n; ++i) {
        auto [l, r] = max_range[i];
        if(l == i) continue;

        auto min_s = st.get(l, i+1);
        if(ps[i+1] - min_s > A[i])
            ret = false;
    }

    return ret;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    auto ans = f(A);
    reverse(A.begin(), A.end());
    ans &= f(A);

    cout << (ans ? "YES" : "NO") << "\n";
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
