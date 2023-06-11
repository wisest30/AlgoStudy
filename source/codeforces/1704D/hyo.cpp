#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> C(vector<vector<ll>>(n, vector<ll>(m)));
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < m; ++j)
            cin >> C[i][j];
    
    vector<ll> S(n);
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < m; ++j)
            S[i] += j * C[i][j];
    
    pair<ll, ll> ret;
    if(S[0] != S[1] && S[0] != S[2]) {
        ret.first = 0;
        ret.second = S[0] - S[1];
    }
    else {
        for(auto i = 1; i < n; ++i) {
            if(S[0] != S[i]) {
                ret.first = i;
                break;
            }
        }
        ret.second = S[ret.first] - S[0];
    }

    cout << (ret.first + 1) << " " << ret.second << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
