#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class SegTree {
private :
    int n;
    vector<long long> T, lazy;

public :
    SegTree() = delete;
    SegTree(int n)
    : n(n), T(4 * n + 20), lazy(4 * n + 20)
    {/* init code */}

private :
    void push(int i, int l, int r)
    {
        T[i] += lazy[i];
        if (l + 1 != r)
        {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
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

ll V(ll a, ll p) {
    if(a == 0) return 0;

    ll ret = 0;
    while(a && a % p == 0)
        ret++, a /= p;
    return ret;
}

ll F(ll a, ll p, ll s) {
    ll x = 1, y = 1;
    for(auto i = 0; i < s; ++i) {
        x *= a;
        y *= a % p;
    }

    auto ret = V(x - y, p);
    return ret;
}

void solve(int TestCase) {
    ll n, q, p;
    cin >> n >> q >> p;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    auto S = vector<SegTree>(5, SegTree(n));
    for(auto s = 1; s <= 4; ++s)
        for(auto i = 0; i < n; ++i)
            S[s].upd(F(A[i], p, s), i, i + 1);

    vector<ll> ret;
    for(auto i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if(type == 1) {
            ll pos, val;
            cin >> pos >> val;
            pos--;
            A[pos] = val;
            for(auto s = 1; s <= 4; ++s) {
                auto old = S[s].get(pos, pos + 1);
                S[s].upd(F(A[pos], p, s) - old, pos, pos + 1);
            }
        }
        else {
            ll s, l, r;
            cin >> s >> l >> r;
            l--;

            auto ans = S[s].get(l, r);
            ret.push_back(ans);
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
