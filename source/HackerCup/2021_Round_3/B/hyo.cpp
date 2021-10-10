#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

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

constexpr int32_t inf = INT32_MAX;
class SimpleSegTree {
private :
    int n;
    vector<int32_t> T[3][3];
    vector<array<bool, 3>> A;
    
public :
    SimpleSegTree() = delete;
    SimpleSegTree(int n)
    : n(n), A(n)
    {
        for(auto i = 0; i < 3; ++i)
            for(auto j = 0; j < 3; ++j)
                T[i][j] = vector<int32_t>(4 * n + 20, inf);
    }

private :
    void put(int i, int l, int r, int y, int x)
    {
        if (r <= y || y < l) return;
        if (l+1 == r)
        {
            T[x][x][i] = 0;
            T[0][1][i] = T[1][0][i] = (T[0][0][i] != inf && T[1][1][i] != inf) ? 1 : inf;
            T[1][2][i] = T[2][1][i] = (T[1][1][i] != inf && T[2][2][i] != inf) ? 1 : inf;
            T[0][2][i] = T[2][0][i] = (T[0][1][i] != inf && T[1][2][i] != inf) ? 2 : inf;
            A[y][x] = true;
            return;
        }
        int m = (l + r) / 2;
        put(i * 2 + 1, l, m, y, x);
        put(i * 2 + 2, m, r, y, x);

        for(auto xm = 0; xm < 3; ++xm) {
            if(m >= n || !A[m-1][xm] || !A[m][xm]) continue;

            for(auto x0 = 0; x0 < 3; ++x0) {
                for(auto x1 = 0; x1 < 3; ++x1) {
                    if(T[x0][xm][i * 2 + 1] == inf) continue;
                    if(T[xm][x1][i * 2 + 2] == inf) continue;

                    T[x0][x1][i] = min(T[x0][x1][i], T[x0][xm][i * 2 + 1] + 1 + T[xm][x1][i * 2 + 2]);
                }
            }
        }
    }
    vector<vector<int>> get(int i, int l, int r, int L, int R)
    {
        if(L <= l && r <= R) {
            auto ret = vector<vector<int>>(3, vector<int>(3, inf));
            for(auto x0 = 0; x0 < 3; ++x0)
                for(auto x1 = 0; x1 < 3; ++x1)
                    ret[x0][x1] = T[x0][x1][i];

            return ret;
        }

        int m = (l + r) / 2;
        if(R <= m) return get(i * 2 + 1, l, m, L, R);
        else if(m <= L) return get(i * 2 + 2, m, r, L, R);
        else {
            auto sub_ret0 = get(i * 2 + 1, l, m, L, R);
            auto sub_ret1 = get(i * 2 + 2, m, r, L, R);
            auto ret = vector<vector<int>>(3, vector<int>(3, inf));
            for(auto xm = 0; xm < 3; ++xm) {
                if(m >= n || !A[m-1][xm] || !A[m][xm]) continue;

                for(auto x0 = 0; x0 < 3; ++x0) {
                    for(auto x1 = 0; x1 < 3; ++x1) {
                        if(sub_ret0[x0][xm] == inf) continue;
                        if(sub_ret1[xm][x1] == inf) continue;
                        ret[x0][x1] = min(ret[x0][x1], sub_ret0[x0][xm] + 1 + sub_ret1[xm][x1]);
                    }
                }
            }
            return ret;
        }
    }

public :
    void put(int y, int x) { put(0, 0, n, y, x); }
    long long get(int L, int R, int x0, int x1) { return get(0, 0, n, L, R)[x0][x1]; }
};

void solve(int TestCase) {
    constexpr int MOD = 1e9 + 7;

    int n, m;
    cin >> n >> m;

    auto A = vector<array<int, 3>>();
    for(auto y = 0; y < n; ++y) {
        for(auto x = 0; x < 3; ++x) {
            array<int, 3> arr;
            cin >> arr[0];
            arr[1] = y, arr[2] = x;
            A.push_back(arr);
        }
    }

    sort(A.begin(), A.end());

    auto B = vector<array<int, 5>>();
    for(auto i = 0; i < m; ++i) {
        array<int, 5> arr;
        cin >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[0];
        arr[1]--, arr[2]--, arr[3]--, arr[4]--;
        if(arr[1] > arr[3]) {
            swap(arr[1], arr[3]);
            swap(arr[2], arr[4]);
        }
        B.push_back(arr);
    }

    sort(B.begin(), B.end());

    vector<FenwickTree> ft;
    for(auto i = 0; i < 3; ++i)
        ft.emplace_back(n);
 
    SimpleSegTree st(n);
    int cur = 0;
    ll ans = 1;
    for(auto i = 0; i < m; ++i) {
        while(cur < A.size() && A[cur][0] <= B[i][0]) {
            st.put(A[cur][1], A[cur][2]);
            ft[A[cur][2]].upd(A[cur][1], 1);
            ++cur;
        }
        
        ll ret = inf;
        for(auto u = 0; u < 2; ++u) {
            for(auto d = 0; d < 2; ++d) {
                int y0, y1, x0, x1;
                ll add = 0;
                if(u == 0) y0 = B[i][1], x0 = B[i][2];
                else {
                    auto cnt = ft[1].get(B[i][1] + 1);
                    if(cnt == 0) continue;
                    y0 = ft[1].upper_bound(cnt - 1);
                    x0 = 1;

                    auto d = abs(B[i][1] - y0) + abs(B[i][2] - x0);
                    if(B[i][2] == 1 || ft[B[i][2]].get(y0, B[i][1] + 1) != d)
                        continue;
                    add += d;
                }

                if(d == 0) y1 = B[i][3], x1 = B[i][4];
                else {
                    auto cnt = ft[1].get(B[i][3]);
                    y1 = ft[1].upper_bound(cnt);
                    if(y1 >= n) continue;
                    x1 = 1;

                    auto d = abs(B[i][3] - y1) + abs(B[i][4] - x1);
                    if(B[i][4] == 1 || ft[B[i][4]].get(B[i][3], y1 + 1) != d)
                        continue;
                    add += d;
                }
                ret = min(ret, st.get(y0, y1 + 1, x0, x1) + add);
            }
        }
        

        if(ret < inf) ans = ans * ret % MOD;
    }

    cout << ans << '\n';
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
