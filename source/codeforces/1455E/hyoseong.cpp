#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 4;
ll X[MAX_N], Y[MAX_N];
void solve(int TestCase) {
    for(auto i = 0; i < 4; ++i)
        cin >> X[i] >> Y[i];
    
    int p[4] = {0, 1, 2, 3};

    ll ret = INT64_MAX;
    do {
        for(auto i = 0; i < 4; ++i) {
            for(auto j = 0; j < 4; ++j) {
                auto x = X[i], y = Y[j];

                auto v = vector<ll>{X[p[1]] - x, X[p[2]] - x, Y[p[2]] - y, Y[p[3]] - y};
                sort(v.begin(), v.end());
                ll len = v[2];

                ll candi = 0;
                candi += abs(x - X[p[0]]) + abs(y - Y[p[0]]);
                candi += abs(x + len - X[p[1]]) + abs(y - Y[p[1]]);
                candi += abs(x + len - X[p[2]]) + abs(y + len - Y[p[2]]);
                candi += abs(x - X[p[3]]) + abs(y + len - Y[p[3]]);
                ret = min(ret, candi);
            }
        }
    } while(next_permutation(p, p + 4));

    cout << ret << endl;
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
