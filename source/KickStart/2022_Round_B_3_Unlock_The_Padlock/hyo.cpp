#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

unordered_map<ll, ll> cache;
int n, d;
vector<ll> A, L, R;

ll recur(ll l, ll r, ll target) {
    if(l == r) return 0;
    if(l + 1 == r) return min(abs(A[l] - target), d - abs(A[l] - target));

    ll key = target * 500 * 500 + l * 500 + r;
    if(cache.count(key))
        return cache[key];

    auto& ret = cache[key];
    ret = INT64_MAX;
    if(L[l] == r - l) {
        ret = min(abs(A[l] - target), d - abs(A[l] - target));
    } else if(A[l] == A[r-1]) {
        auto sub_ret = recur(l + L[l], r - R[r], A[l]);
        ret = min(abs(A[l] - target), d - abs(A[l] - target)) + sub_ret;
    } else {
        auto sub_ret = recur(l + L[l], r, A[l]);
        ret = min(abs(A[l] - target), d - abs(A[l] - target)) + sub_ret;

        sub_ret = recur(l, r - R[r], A[r-1]);
        auto candi = min(abs(A[r-1] - target), d - abs(A[r-1] - target)) + sub_ret;

        ret = min(ret, candi);
    }

    //cout << "debug " << l << " " << r << " " << target << " " << ret << endl;
    return ret;
}

void solve(int TestCase) {
    cache.clear();
    cin >> n >> d;

    A.resize(n);
    for(auto& x : A) cin >> x;

    L = vector<ll>(n+1);
    R = L;
    for(auto l = 0; l < n; ++l) {
        for(auto i = l; i < n; ++i) {
            if(A[l] == A[i]) {
                L[l]++;
            } else {
                break;
            }
        }
    }
    for(auto r = n; r >= 1; --r) {
        for(auto i = r - 1; i >= 0; --i) {
            if(A[r-1] == A[i]) {
                R[r]++;
            } else {
                break;
            }
        }
    }

    auto ret = recur(0, n, 0);
    cout << ret << "\n";
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

