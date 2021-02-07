#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

// sum
class SegTree {
private :
    int n;
    vector<long long> T, lazy;

public :
    SegTree() = delete;
    SegTree(int n)
    : n(n), T(4 * n + 20), lazy(4 * n + 20, -1)
    {/* init code */}

private :
    void push(int i, int l, int r)
    {
        if(lazy[i] == -1) return;
        T[i] = lazy[i] ? (r-l):0;
        if (l + 1 != r)
        {
            lazy[2 * i + 1] = lazy[i];
            lazy[2 * i + 2] = lazy[i];
        }
        lazy[i] = -1;
    }

    void pull(int i) { T[i] = T[i * 2 + 1] + T[i * 2 + 2]; }

    void upd(int i, int l, int r, long long val, int L, int R)
    {
        push(i, l, r);
        if (r <= L || R <= l) return;
        if (L <= l && r <= R)
        {
            lazy[i] = val;
            push(i, l, r);
            return;
        }
        int m = (l + r) / 2;
        upd(i * 2 + 1, l, m, val, L, R);
        upd(i * 2 + 2, m, r, val, L, R);
        pull(i);
    }
    long long get(int i, int l, int r, int L, int R)
    {
        push(i, l, r);
        if(L <= l && r <= R)
            return T[i];

        int m = (l + r) / 2;
        long long ret = 0;
        if(L < m)
            ret += get(i * 2 + 1, l, m, L, R);
        if(R > m)
            ret += get(i * 2 + 2, m, r, L, R);

        return ret;
    }

public :
    void upd(long long val, int L, int R) { upd(0, 0, n, val, L, R); }
    long long get(int L, int R) { return get(0, 0, n, L, R); }
};

void solve(int TestCase) {
    int n, q;
    cin >> n >> q;

    string s, f;
    cin >> s >> f;

    vector<pair<int, int>> Q(q);
    for(auto& q : Q) {
        cin >> q.first >> q.second;
        q.first--;
    }

    SegTree st(n);
    for(auto i = 0; i < n; ++i)
        st.upd(f[i] - '0', i, i+1);

    for(auto i = q-1; i >= 0; --i) {
        int l = Q[i].first, r = Q[i].second;
        auto one_cnt = st.get(l, r);
        auto zero_cnt = r - l - one_cnt;

        if(one_cnt == zero_cnt) {
            cout << "NO" << endl;
            return;
        }

        st.upd(one_cnt < zero_cnt ? 0 : 1, l, r);
    }

    for(auto i = 0; i < n; ++i) {
        if(s[i] - '0' != st.get(i, i+1)) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
