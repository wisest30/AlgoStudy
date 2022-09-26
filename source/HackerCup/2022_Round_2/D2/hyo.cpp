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

    vector<FenwickTree> F(5, FenwickTree(n));
    for(auto i = 0; i < n; ++i) {
        int val;
        cin >> val;

        F[0].upd(i, val);
        F[val].upd(i, 1);
        F[val + 2].upd(i, i);
    }

    ll ret = 0;
    for(auto i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        auto old = F[0].get(x, x+1);
        F[0].upd(x, y - old);
        F[old].upd(x, -1);
        F[old + 2].upd(x, -x);
        F[y].upd(x, 1);
        F[y + 2].upd(x, x);
        auto lsum = F[0].get(z), rsum = F[0].get(z, n);
        auto d = abs(lsum - rsum);
        auto l1 = F[1].get(z), l2 = F[2].get(z);
        auto r1 = F[1].get(z, n), r2 = F[2].get(z, n);
        auto possible = lsum < rsum ? min(l1, r2) : min(l2, r1);
        if(d == 0) continue;
        else if(d % 2 || possible < d / 2) {
            ret--;
            continue;
        }
        d /= 2;
        auto lp = lsum < rsum ? F[1].upper_bound(l1 - d) : F[2].upper_bound(l2 - d);
        auto rp = lsum < rsum ? F[2].upper_bound(l2 + d - 1) + 1: F[1].upper_bound(l1 + d - 1) + 1;
        auto lpsum = F[lsum < rsum ? 3 : 4].get(lp, z);
        auto rpsum = F[lsum < rsum ? 4 : 3].get(z, rp);
        ret += rpsum - lpsum;
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
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}

