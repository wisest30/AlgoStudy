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
};

void solve(int TestCase) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto mod = [](auto x) {
        return (x % 3 + 3) % 3;
    };

    ll ret = 0, cur = 0;
    vector<FenwickTree> f(3, FenwickTree(2 * n + 1));
    f[0].upd(n, 1);
    for(auto i = 0; i < n; ++i) {
        cur += s[i] == '+' ? -1 : 1;
        ret += f[mod(cur)].get(cur + n + 1);
        f[mod(cur)].upd(cur + n, 1);
    }

    cout << ret << "\n";
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
