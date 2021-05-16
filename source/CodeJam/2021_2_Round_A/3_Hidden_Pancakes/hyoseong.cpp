#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

#include<bits/stdc++.h>
 
using namespace std;

class SimpleSegTree {
private :
    int n;
    vector<long long> T;
    vector<int> I;

public :
    SimpleSegTree() = delete;
    SimpleSegTree(int n)
    : n(n), T(4 * n + 20), I(4 * n + 20)
    {/* init code */}

private :
    void put(int i, int l, int r, long long val, int idx)
    {
        if (r <= idx || idx < l) return;
        if (l+1 == r)
        {
            T[i] = val;
            I[i] = idx;
            return;
        }
        int m = (l + r) / 2;
        put(i * 2 + 1, l, m, val, idx);
        put(i * 2 + 2, m, r, val, idx);
        T[i] = min(T[i * 2 + 1], T[i * 2 + 2]);
        I[i] = T[i * 2 + 1] < T[i * 2 + 2] ? I[i * 2 + 1] : I[i * 2 + 2];
    }
    pair<long long, int> get(int i, int l, int r, int L, int R)
    {
        if(L <= l && r <= R)
            return {T[i], I[i]};

        int m = (l + r) / 2;
        auto ret = make_pair(numeric_limits<long long>::max(), -1);
        if(L < m)
            ret = get(i * 2 + 1, l, m, L, R);
        if(R > m) {
            auto sub_ret = get(i * 2 + 2, m, r, L, R);
            if(sub_ret.first <= ret.first)
                ret = sub_ret;
        }

        return ret;
    }

public :
    void put(long long val, int idx) { put(0, 0, n, val, idx); }
    pair<long long, int> get(int L, int R) { return get(0, 0, n, L, R); }
};

class Combination2 {
    using T = unsigned long long;
    T MOD;
    vector<T> fact;
public :
    Combination2(int n, T MOD = 0)
    : MOD(MOD), fact(n+1) {
        fact[0] = 1;
        for(auto i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
    }

    T pow_mod(long long x, long long y, long long mod) {
        auto ret=1ll;
        while (y) {
                if (y % 2)
                    ret = ret * x % mod;
                x =  x * x % mod;
                y /= 2;
            }
        return ret;
    }

    T nCr(int n, int r) {
        return fact[n] * pow_mod(fact[n-r], MOD - 2, MOD) % MOD * pow_mod(fact[r], MOD - 2, MOD) % MOD;
    }
};

constexpr int MOD = 1e9 + 7;
int n;

ll recur(SimpleSegTree& st, Combination2& combi, int l, int r) {
    if(l == r || l + 1 == r) return 1;

    auto min_idx = st.get(l, r).second;

    auto sub_ret0 = recur(st, combi, l, min_idx);
    auto sub_ret1 = recur(st, combi, min_idx + 1, r);

    auto remain_cnt = r - l - 1;
    auto left_cnt = min_idx - l;

    auto ret = sub_ret0 * sub_ret1 % MOD * combi.nCr(remain_cnt, left_cnt) % MOD;
    return ret;
}

void solve(int TestCase) {
    cin >> n;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    for(auto i = 0; i < n - 1; ++i) {
        if(A[i] + 1 < A[i+1]) {
            cout << 0 << endl;
            return;
        }
    }

    SimpleSegTree st(n);
    for(auto i = 0; i < n; ++i)
        st.put(A[i], i);
    
    Combination2 combi(n, MOD);

    auto ret = recur(st, combi, 0, n);
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
