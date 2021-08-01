#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#include<bits/stdc++.h>
 
using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

class SimpleSegTree {
private :
    int n;
    vector<long long> T;

public :
    SimpleSegTree() = delete;
    SimpleSegTree(int n)
    : n(n), T(4 * n + 20)
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
        T[i] = gcd(T[i * 2 + 1], T[i * 2 + 2]);
    }
    long long get(int i, int l, int r, int L, int R)
    {
        if(L <= l && r <= R)
            return T[i];

        int m = (l + r) / 2;
        long long ret = 0;
        if(L < m)
            ret = gcd(ret, get(i * 2 + 1, l, m, L, R));
        if(R > m)
            ret = gcd(ret, get(i * 2 + 2, m, r, L, R));

        return ret;
    }

public :
    void put(long long val, int idx) { put(0, 0, n, val, idx); }
    long long get(int L, int R) { return get(0, 0, n, L, R); }
};

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    SimpleSegTree st(n);
    for(auto i = 0; i < n; ++i)
        st.put(A[i], i);
    
    auto check = [&](int m) {
        auto x = st.get(0, m + 1);
        for(auto i = 1; i < n; ++i) {
            auto g = st.get(i, min(i + m + 1, n));
            if(i + m + 1 > n) {
                auto g2 = st.get(0, i + m + 1 - n);
                g = gcd(g, g2);
            }

            if(g != x)
                return false;
        }    

        return true;
    };

    int l = -1, r = n;
    while(l + 1 < r) {
        int m = (l+r) / 2;
        if(check(m))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
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
