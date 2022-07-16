#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

class PSum {
    using T = long long;
    vector<T> ps;

public :
    template<typename U>
    PSum(const vector<U>& A)
    : ps(A.size() + 1)
    {
        for(auto i = 1; i < ps.size(); ++i)
            ps[i] = ps[i-1] + A[i-1];
    }

    T get(int left, int right) {
        return ps[right] - ps[left];
    }
};


ll n, m, k;
vector<ll> A, B;

void solve(int TestCase) {
    cin >> n;
    A = vector<ll>(n);
    for(auto& a : A) cin >> a;
    cin >> m;
    B = vector<ll>(m);
    for(auto& b : B) cin >> b;
    cin >> k;

    PSum as(A), bs(B);
    vector<ll> C(k + 1), D(k + 1);
    for(auto l = 0; l < A.size(); ++l) {
        for(auto r = l; r <= A.size(); ++r) {
            auto d = n - (r - l);
            if(d <= k) {
                C[d] = max(C[d], as.get(0, n) - as.get(l, r));
            }
        }
    }
    for(auto l = 0; l < B.size(); ++l) {
        for(auto r = l; r <= B.size(); ++r) {
            auto d = m - (r - l);
            if(d <= k) {
                D[d] = max(D[d], bs.get(0, m) - bs.get(l, r));
            }
        }
    }

    ll ret = 0;
    for(auto i = 0; i <= k; ++i) {
        ret = max(ret, C[i] + D[k - i]);
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
