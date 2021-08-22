#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

ll r, c, k, r0, c0, r1, c1;
ll cnt_line(ll len) { return (len + k - 1) / k; }
ll min_cut_inner(ll len_r, ll len_c) {
    if(len_r == 0 || len_c == 0) return 0;
    else if(len_r <= k && len_c <= k) return len_r * len_c - 1;
    else if(len_c > k) return min_cut_inner(len_r, k) + min_cut_inner(len_r, len_c - k) + cnt_line(len_r);
    else return min_cut_inner(len_c, len_r);
}
ll min_perimeter() {
    auto len_r = r1 - r0;
    auto len_c = c1 - c0;
    auto cnt_r = cnt_line(len_r);
    auto cnt_c = cnt_line(len_c);

    if(r0 != 0 && r1 != r && c0 != 0 && c1 != c) {
        ll ret = INT64_MAX;
        ret = min(ret, cnt_line(r1) + cnt_r + cnt_c * 2);
        ret = min(ret, cnt_line(r - r0) + cnt_r + cnt_c * 2);
        ret = min(ret, cnt_line(c1) + cnt_r * 2 + cnt_c);
        ret = min(ret, cnt_line(c - c0) + cnt_r * 2 + cnt_c);
        return ret;
    }
    else {
        ll ret = 0;
        if(r0 != 0) ret += cnt_c;
        if(r1 != r) ret += cnt_c;
        if(c0 != 0) ret += cnt_r;
        if(c1 != c) ret += cnt_r;
        return ret;
    }
}

void solve(int TestCase) {
    cin >> r >> c >> k;
    cin >> r0 >> c0 >> r1 >> c1;
    r0--, c0--;

    auto ret = min_perimeter() + min_cut_inner(r1 - r0, c1 - c0);
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
