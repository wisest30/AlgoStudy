#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;
void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll len = 0;
    for(auto i = 0; i < n; ++i) {
        if(s[i] == '.') {
            len = len * 2 % MOD;
        } else {
            len = (len + 1) % MOD;
        }
    }

    auto first = tuple<char, ll>('_', -1);
    auto last = tuple<char, ll>('_', -1);
    ll lr_sum = 0, l_sum = 0, r_sum = 0, cur = 0, cnt = 0;
    for(auto i = 0; i < n; ++i) {
        if(s[i] == 'O' || s[i] == 'X') {
            if(get<0>(first) == '_') {
                first = tuple<char, ll>(s[i], cur);
            } else if(get<0>(last) != s[i]) {
                ll l = (get<1>(last) + 1) % MOD;
                ll r = (len - cur + MOD) % MOD;
                ll lr = l * r % MOD;
                lr_sum = (lr_sum + lr) % MOD;
                l_sum = (l_sum + l) % MOD;
                r_sum = (r_sum + r) % MOD;
                cnt = (cnt + 1) % MOD;
            }

            last = tuple<char, ll>(s[i], cur);
            cur = (cur + 1) % MOD;
        } else if(s[i] == '.') {
            if(get<0>(first) != '_') {
                ll add = lr_sum;
                add = (add + cur * r_sum % MOD) % MOD;
                add = (add - cur * l_sum % MOD + MOD) % MOD;
                add = (add - cur * cur % MOD * cnt % MOD + MOD) % MOD;

                lr_sum = (lr_sum + add) % MOD;
                l_sum = (l_sum + l_sum + cnt * cur % MOD) % MOD;
                r_sum = (r_sum + r_sum - cnt * cur % MOD + MOD) % MOD;
                cnt = cnt * 2 % MOD;

                if(get<0>(first) != get<0>(last)) {
                    ll l = (get<1>(last) + 1) % MOD;
                    ll r = (len - (get<1>(first) + cur) % MOD + MOD) % MOD;
                    ll lr = l * r % MOD;
                    lr_sum = (lr_sum + lr) % MOD;
                    l_sum = (l_sum + l) % MOD;
                    r_sum = (r_sum + r) % MOD;
                    cnt = (cnt + 1) % MOD;
                }

                auto [c, idx] = last;
                last = tuple<char, ll>(c, (cur + idx) % MOD);
            }

            cur = cur * 2 % MOD;
        } else {
            cur = (cur + 1) % MOD;
        }
    }

    cout << lr_sum << "\n";
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
