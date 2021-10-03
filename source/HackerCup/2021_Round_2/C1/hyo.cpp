#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int r, c, k;
    cin >> r >> c >> k;
    k--;

    vector<string> A(r);
    for(auto& x : A) cin >> x;

    auto usum = vector<vector<int>>(r+1, vector<int>(c));
    for(auto y = 1; y <= r; ++y)
        for(auto x = 0; x < c; ++x)
            usum[y][x] = usum[y-1][x] + (A[y-1][x] == 'X');

    int ret = INT_MAX;
    for(auto y = -1; y <= r; ++y) {
        int candi = abs(y - k);
        for(auto x = 0; x < c; ++x) {
            if(y >= 0 && y < r && A[y][x] == 'X') {
                candi++;
            } else {
                int need = y < k ? r - k : k + 1;
                int cnt = y < k ? usum[r][x] - usum[max(0, y)][x] : usum[min(r, y+1)][x];
                if(cnt >= need)
                    candi++;
            }
        }

        ret = min(ret, candi);
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
