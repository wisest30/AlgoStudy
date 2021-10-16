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

void solve(int TestCase) {
    ll n, k;
    cin >> n >> k;

    vector<ll> A(n);
    for(auto& x : A) cin >> x;

    if(k == 0) {
        cout << 0 << endl;
        return;
    }

    PSum ps(A);

    vector<vector<pair<int, int>>> S(k+1);
    for(auto i = 0; i < n; ++i) {
        for(auto j = i + 1; j <= n; ++j) {
            ll su = ps.get(i, j);
            if(su <= k)
                S[su].push_back({i, j});
        }
    }

    vector<vector<int>> T(k+1);
    for(auto su = 0; su <= k; ++su) {
        T[su].resize(S[su].size());
        for(auto i = (int)S[su].size() - 1; i >= 0; --i) {
            T[su][i] = S[su][i].second - S[su][i].first;
            if(i < (int)S[su].size() - 1)
                T[su][i] = min(T[su][i], T[su][i+1]);
        }
    }

    int ret = n + 1;
    for(auto& p : S[k])
        ret = min(ret, p.second - p.first);

    for(ll su = 1; su < k; ++su) {
        for(auto& p : S[su]) {
            int l = p.first, r = p.second;
            ll su2 = k - su;

            auto q = lower_bound(S[su2].begin(), S[su2].end(), make_pair(r, 0)) - S[su2].begin();
            if(q != S[su2].size())
                ret = min(ret, r - l + T[su2][q]);
        }
    }

    if(ret > n) cout << -1 << endl;
    else cout << ret << endl;
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
