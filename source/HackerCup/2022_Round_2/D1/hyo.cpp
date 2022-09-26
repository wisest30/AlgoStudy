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

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<FenwickTree> F(4, FenwickTree(n));
    for(auto i = 0; i < n; ++i) {
        int x;
        cin >> x;
        F[0].upd(i, x);
        F[x].upd(i, 1);
    }

    ll ans = 0;
    for(auto i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        auto old = F[0].get(x, x+1);
        F[0].upd(x, y-old);
        F[old].upd(x, -1);
        F[y].upd(x, 1);

        auto lsum = F[0].get(z), rsum = F[0].get(z, n);
        auto d = abs(lsum - rsum);
        auto l1 = F[1].get(z), r1 = F[1].get(z, n);
        auto l2 = F[2].get(z), r2 = F[2].get(z, n);
        auto l3 = F[3].get(z), r3 = F[3].get(z, n);
        auto ret = 0;
        if(lsum > rsum) {
            swap(lsum, rsum);
            swap(l1, r1);
            swap(l2, r2);
            swap(l3, r3);
        }

        auto cnt = min(min(l1, r3), d / 4);
        l1 -= cnt, l3 += cnt;
        r1 += cnt, r3 -= cnt;
        d -= 4 * cnt;
        ret += cnt;

        cnt = min(min(l1, r2), d / 2);
        l1 -= cnt, l2 += cnt;
        r1 += cnt, r2 -= cnt;
        d -= 2 * cnt;
        ret += cnt;

        cnt = min(min(l2, r3), d / 2);
        l2 -= cnt, l3 += cnt;
        r2 += cnt, r3 -= cnt;
        d -= 2 * cnt;
        ret += cnt;

        if(d != 0) ret = -1;

        ans += ret;
    }

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

