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
    int n, k;
    cin >> n >> k;

    if(k > n)
        k = n;

    map<int, int> cnt_map;
    for(auto i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt_map[x]++;
    }

    FenwickTree ft0(n+1), ft1(n+1);
    for(auto [x, cnt] : cnt_map) {
        ft0.upd(cnt, 1);
        ft1.upd(cnt, cnt);
    }

    ll ret = INT_MAX;
    auto zero_cnt = 0;
    for(auto mex = 0; mex <= n; ++mex) {
        if(zero_cnt > k) break;
        if(ft1.get(n+1) <= k) {
            ret = 0;
            break;
        }

        auto p = ft1.upper_bound(k);
        ret = min(ret, ft0.get(p, n+1) - (k - ft1.get(p)) / p);

        if(cnt_map.count(mex) == 0) zero_cnt++;
        else ft0.upd(cnt_map[mex], -1), ft1.upd(cnt_map[mex], -cnt_map[mex]);
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
