#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int n = s.size();
    auto A = vector<vector<int>>(26, vector<int>(n+1));

    for(auto i = 1; i <= n; ++i) {
        for(auto j = 0; j < 26; ++j) A[j][i] = A[j][i-1];
        auto c = s[i-1] - 'a';
        A[c][i]++;
    }

    int q;
    cin >> q;
    int ret = 0;
    for(auto i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;

        if((r - l) % 2 == 0) continue;
        auto m = (l + r) / 2 + 1;
        vector<int> a(26), b(26);
        for(auto j = 0; j < 26; ++j) {
            a[j] = A[j][m] - A[j][l];
            b[j] = A[j][r] - A[j][m];
        }

        int diff = 0;
        for(auto j = 0; j < 26; ++j) {
            diff += abs(a[j] - b[j]);
        }

        if(diff == 1) {
            ret++;
            continue;
        }

        {
            auto m = (l + r) / 2;
            vector<int> a(26), b(26);
            for(auto j = 0; j < 26; ++j) {
                a[j] = A[j][m] - A[j][l];
                b[j] = A[j][r] - A[j][m];
            }

            int diff = 0;
            for(auto j = 0; j < 26; ++j) {
                diff += abs(a[j] - b[j]);
            }

            if(diff == 1) {
                ret++;
                continue;
            }
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

