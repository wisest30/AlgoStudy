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

int n, m, q;
int fidx(int y, int x) {
    return x * n + y;
}

void solve(int TestCase) {
    cin >> n >> m >> q;

    vector<string> A(n);
    for(auto& x : A) cin >> x;

    FenwickTree ft(n * m);
    for(auto y = 0; y < n; ++y)
        for(auto x = 0; x < m; ++x)
            if(A[y][x] == '*')
                ft.upd(fidx(y, x), 1);
    
    for(auto i = 0; i < q; ++i) {
        int y, x;
        cin >> y >> x;
        y--, x--;

        if(A[y][x] == '*') {
            ft.upd(fidx(y, x), -1);
            A[y][x] = '.';
        } else {
            ft.upd(fidx(y, x), 1);
            A[y][x] = '*';
        }

        auto total = ft.get(n * m);
        auto ans = total - ft.get(total);
        cout << ans << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
