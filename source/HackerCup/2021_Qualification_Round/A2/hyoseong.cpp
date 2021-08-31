#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int n;
    cin >> n;

    constexpr int inf = 10000;
    vector<vector<int>> A(26, vector<int>(26, inf));
    for(auto i = 0; i < n; ++i) {
        string x;
        cin >> x;
        A[x[0] - 'A'][x[1] - 'A'] = 1;
    }

    for(auto i = 0; i < 26; ++i)
        A[i][i] = 0;
    
    for(auto k = 0; k < 26; ++k)
        for(auto i = 0; i < 26; ++i)
            for(auto j = 0; j < 26; ++j)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);

    int ret = inf;
    for(char to = 'A'; to <= 'Z'; ++to) {
        int candi = 0;
        for(auto c : s) {
            candi += A[c - 'A'][to - 'A'];
            candi = min(candi, inf);
        }

        ret = min(ret, candi);
    }

    if(ret == inf)
        ret = -1;

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
