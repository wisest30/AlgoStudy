#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
void solve(int TestCase) {
    int n, k;
    cin >> n >> k;

    vector<array<int, 4>> A(n);
    for(auto& x : A) cin >> x[0] >> x[2] >> x[1] >> x[3];
    sort(A.begin(), A.end());

    vector<multiset<ll>> S(n);
    multiset<ll> empty_set, ans_set;
    for(auto i = n-1; i >= 0; --i) {    
        S[i].insert(A[i][1]);
        
        auto l = lower_bound(A.begin() + i, A.end(), array<int, 4>{A[i][2], A[i][3] + 1, 0, 0}) - A.begin();
        auto r = lower_bound(A.begin() + l, A.end(), array<int, 4>{A[i][2] + 1, 0, 0, 0}) - A.begin();

        auto& merge_set = l == r ? empty_set : S[l];
        for(auto x : merge_set) {
            S[i].insert(x - A[i][3] + A[i][1]);
            while(S[i].size() > k) S[i].erase(S[i].begin());
        }

        for(auto x : S[i]) {
            ans_set.insert(x - A[i][1]);
            if(ans_set.size() > k) ans_set.erase(ans_set.begin());
        }

        if(i < n - 1 && A[i][0] == A[i+1][0]) {
            for(auto x : S[i+1]) {
                S[i].insert(x);
                if(S[i].size() > k) S[i].erase(S[i].begin());
            }
        }
        
    }

    ll ans = 0;
    for(auto x : ans_set) ans = (ans + x) % MOD;

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

