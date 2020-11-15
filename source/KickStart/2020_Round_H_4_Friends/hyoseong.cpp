#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 5 * 10000 + 10;
int n, q;
string S[MAX_N];
pair<int, int> Q[MAX_N];

void solve(int TestCase) {
    int n;
    cin >> n >> q;
    for(auto i = 0; i < n; ++i) cin >> S[i];
    for(auto i = 0; i < q; ++i) {
        cin >> Q[i].first >> Q[i].second;
        Q[i].first--, Q[i].second--;
    }


    auto M = vector<vector<int>>(26, vector<int>(26, 1000));
    for(auto i = 0; i < n; ++i)
        for(auto j = 0; j < S[i].size(); ++j)
            for(auto k = 0; k < S[i].size(); ++k)
                M[S[i][j] - 'A'][S[i][k] - 'A'] = 1;
    for(auto i = 0; i < 26; ++i)
        M[i][i] = 0;
    
    for(auto k = 0; k < 26; ++k)
        for(auto i = 0; i < 26; ++i)
            for(auto j = 0; j < 26; ++j)
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
    
    for(auto i = 0; i < q; ++i) {
        int min_val = INT_MAX;
        for(auto c1 : S[Q[i].first])
            for(auto c2 : S[Q[i].second])
                min_val = min(min_val, M[c1 - 'A'][c2 - 'A']);
        
        if(min_val >= 1000) cout << -1 << " ";
        else cout << (min_val + 2) << " ";
    }

    cout << endl;
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
