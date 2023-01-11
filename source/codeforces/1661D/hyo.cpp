#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll n, k;
    cin >> n >> k;

    vector<ll> B(n);
    for(auto& x : B) cin >> x;

    vector<ll> cnt(n + k);
    ll mul_sum = 0, cnt_sum = 0;
    for(auto i = n-1; i >= 0; --i) {
        ll cur = B[i] - mul_sum;
        if(i >= k-1) {
            cnt[i] = max(0ll, (cur + k - 1) / k);
        } else {
            ll p = i + 1;
            ll add = max(0ll, (cur + p - 1) / p);
            cnt[k-1] += add;
            mul_sum += add * (i + 1);
            cnt_sum += add;
        }

        mul_sum -= cnt_sum;
        mul_sum += (k - 1) * cnt[i];
        cnt_sum -= cnt[i + k - 1];
        cnt_sum += cnt[i];
    }

    auto ret = accumulate(cnt.begin(), cnt.end(), 0ll);
    cout << ret << endl;
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
