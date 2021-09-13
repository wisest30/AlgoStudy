#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;
void solve(int TestCase) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int distance = n + m - 1;
    if(distance > a || distance > b) {
        cout << "Impossible\n"; 
    } else {
        cout << "Possible\n";

        auto ret = vector<vector<int>>(n, vector<int>(m, 1));
        ret[0][0] = a - (distance - 1);
        ret[0][m-1] = b - (distance - 1);

        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < m; ++j) {
                cout << ret[i][j] << " ";
            }
            cout << "\n";
        }
    }
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
