#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

ll solve2(const vector<ll>& sorted,
          const vector<ll>& ps,
          ll n,
          int idx)
{
    ll ret = 0;
    int w = sorted.size();
    auto key = sorted[idx];
    auto p = lower_bound(sorted.begin(), sorted.end(), key - n / 2)
             - sorted.begin();
    auto q = upper_bound(sorted.begin(), sorted.end(), key + n / 2)
             - sorted.begin();

    ret += ps[p] + (n - key) * p;
    ret += (idx - p) * key - (ps[idx] - ps[p]);
    ret += ps[q] - ps[idx+1] - (q - idx - 1) * key;
    ret += (w - q) * (n + key) - (ps.back() - ps[q]);
    return ret;
}

void solve(int TestCase) {
    int w;
    ll n;
    cin >> w >> n;

    vector<ll> sorted(w);
    for(auto& x : sorted)
        cin >> x;
    
    sort(sorted.begin(), sorted.end());
    vector<ll> ps(w+1);
    for(auto i = 1; i <= w; ++i)
        ps[i] = ps[i-1] + sorted[i-1];

    ll ret = numeric_limits<ll>::max();
    for(auto i = 0; i < w; ++i)
        ret = min(ret, solve2(sorted, ps, n, i));

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

