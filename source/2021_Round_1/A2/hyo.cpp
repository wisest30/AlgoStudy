#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;
void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    char last_c = '_';
    auto last_i = -1;
    ll ret = 0;
    for(auto i = 0; i < n; ++i) {
        auto c = s[i];

        if(last_c != '_' && c != 'F' && c != last_c) {
            ret += (ll)(last_i + 1) * (n - i);
            ret %= MOD;
        }

        if(c != 'F') {
            last_c = c;
            last_i = i;
        }
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
