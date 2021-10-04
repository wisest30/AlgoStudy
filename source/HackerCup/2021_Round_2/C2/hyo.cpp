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

    void pull(int i) { T[i] = min(T[i * 2 + 1], T[i * 2 + 2]); }

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
        long long ret = INT64_MAX;
        if(L < m)
            ret = min(ret, get(i * 2 + 1, l, m, L, R));
        if(R > m)
            ret = min(ret, get(i * 2 + 2, m, r, L, R));

        return ret;
    }

public :
    void upd(long long val, int L, int R) { upd(0, 0, n, val, L, R); }
    long long get(int L, int R) { return get(0, 0, n, L, R); }
};

class FenwickTree {
public:
    int N;
    vector<long long> f;
    FenwickTree(int N) : N(N), f(vector<long long>(N+10)) {}
    void upd(int i, long long val) {
        assert(i >= 0 && i < N);
        for(; i < f.size(); i |= i+1) f[i] += val;
    }

    long long get(int i) {
        assert(i >= 0 && i <= N);
        if(i == 0) return 0;
        i--;

        long long ret = 0;
        for(; i >= 0; i = (i & (i+1)) - 1) ret += f[i];
        return ret;
    }

    long long get(int l, int r) {
        assert(l >= 0 && l <= N);
        assert(r >= 0 && r <= N);
        return get(r) - get(l);
    }

    // upper_bound get(i) <= k
    int upper_bound(long long k) {
        if(get(N) <= k)
            return N;

        int i = 0, right = 0;
        long long sum = 0;
        while((1 << (i + 1)) <= N) ++i;
        while(true) {
            while(right + (1 << i) - 1 >= N) --i;
            auto nxt_sum = sum + f[right + (1 << i) - 1];
            if(nxt_sum <= k) {
                sum = nxt_sum;
                right |= 1 << i;
            }
            if(i == 0 || right == N) break;
            else --i;
        }

        return right;
    }
};

void solve(int TestCase) {
    int r, c, k, s;
    cin >> r >> c >> k >> s;
    k--;

    vector<string> A(r);
    for(auto& x : A) cin >> x;

    vector<array<int, 2>> S(s);
    for(auto& x : S) {
        cin >> x[0] >> x[1];
        x[0]--, x[1]--;
    }

    vector<long long> answers(s, INT64_MAX);
    for(auto down = 0; down <= 1; ++down) {
        auto ft = vector<FenwickTree>(c, FenwickTree(r+1));
        for(auto y = 0; y < r; ++y)
            for(auto x = 0; x < c; ++x)
                if(A[y][x] == 'X') ft[x].upd(y, 1);

        SegTree st(r+1);
        for(auto y = k; y <= r; ++y) {
            long long val = y - k;
            for(auto x = 0; x < c; ++x)
                if((y < r && A[y][x] == 'X') || ft[x].get(y) >= k + 1)
                    ++val;
            st.upd(val, y, y+1);
        }

        auto copyA = A;
        for(auto i = 0; i < s; ++i) {
            int y = S[i][0], x = S[i][1];
            if(copyA[y][x] == 'X') {
                
                auto old_y = ft[x].upper_bound(k);
                copyA[y][x] = '.';
                ft[x].upd(y, -1);
                auto new_y = ft[x].upper_bound(k);

                if(old_y != new_y) st.upd(-1, old_y+1, new_y);
                if(y <= old_y) st.upd(-1, y, y+1);
            } else {
                auto old_y = ft[x].upper_bound(k);
                copyA[y][x] = 'X';
                ft[x].upd(y, 1);
                auto new_y = ft[x].upper_bound(k);

                if(old_y != new_y) st.upd(1, new_y+1, old_y);
                if(y <= new_y) st.upd(1, y, y+1);
            }

            answers[i] = min(answers[i], st.get(k, r+1));
        }

        reverse(A.begin(), A.end());
        k = r - (k + 1);
        for(auto i = 0; i < s; ++i) S[i][0] = r - (S[i][0] + 1);
    }

    auto ans = accumulate(answers.begin(), answers.end(), 0ll);
    cout << ans << endl;
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
