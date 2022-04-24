#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll a;
    cin >> a;

    auto factors = vector<ll>();
    for(ll i = 1; i * i <= a; ++i) {
        if(a % i == 0) {
            ll j = a / i;
            factors.push_back(i);
            if(i != j) factors.push_back(j);
        }
    }

    ll ret = 0;
    for(auto& f : factors) {
        string s = to_string(f);
        bool add = true;
        for(auto i = 0; i < s.size() / 2; ++i) {
            if(s[i] != s[(int)s.size() - 1 - i]) {
                add = false;
                break;
            }
        }

        ret += add;
    }

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

