#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, p;
    cin >> n >> p;

    auto A = vector<vector<ll>>(n+1, vector<ll>(p));
    auto B = vector<vector<ll>>(n+1, vector<ll>(p, INT64_MAX));
    for(auto i = 0; i < B[0].size(); ++i)
        B[0][i] = 0;

    for(auto i = 1; i < A.size(); ++i) {
        for(auto& x : A[i]) cin >> x;
        sort(A[i].begin(), A[i].end());
        A[i].erase(unique(A[i].begin(), A[i].end()), A[i].end());
    }
    
    for(auto k = 1; k < A.size(); ++k) {
        for(auto i = 0; i < A[k-1].size(); ++i) {
            for(auto j = 0; j < A[k].size(); ++j) {
                B[k][j] = min(B[k][j], B[k-1][i] + min(abs(A[k-1][i] - A[k][0]) + abs(A[k][0] - A[k].back()) + abs(A[k].back() - A[k][j]),
                           abs(A[k-1][i] - A[k].back()) + abs(A[k][0] - A[k].back()) + abs(A[k][0] - A[k][j])));
            }
        }
    }

    auto ret = *min_element(B.back().begin(), B.back().begin() + A.back().size());
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