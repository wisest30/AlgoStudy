#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll n, d, c, m;
    cin >> n >> d >> c >> m;

    string s;
    cin >> s;

    bool ret = true;
    for(auto i = 0; i < n; ++i) {
        if(s[i] == 'C') {
            if(c == 0) {
                for(auto j = i+1; j < n; ++j) {
                    if(s[j] == 'D') {
                        ret = false;
                        break;
                    }
                }
                break;
            } else {
                --c;
            }
        } else {
            if(d == 0) {
                ret = false;
                break;
            } else {
                --d;
                c += m;
            }
        }
    }

    if(ret) cout << "YES" << endl;
    else cout << "NO" << endl;
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
