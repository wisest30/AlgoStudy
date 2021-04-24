#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_VAL = 3e5 + 1;
void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    vector<int> L(n, 2), R(n, 2);
    L[0] = R[n-1] = 1;
    for(auto i = 2; i < n; ++i)
        L[i] = A[i] - A[i-1] == A[i-1] - A[i-2] ? L[i-1] + 1 : 2;
    for(auto i = n-3; i >= 0; --i)
        R[i] = A[i+2] - A[i+1] == A[i+1] - A[i] ? R[i+1] + 1 : 2;
    
    auto ret = *max_element(L.begin(), L.end());

    for(auto i = 0; i < n; ++i) {
        if(i == 0) ret = max(ret, R[i+1] + 1);
        else if(i == n-1) ret = max(ret, L[i-1] + 1);
        else {
            ret = max(ret, L[i-1] + 1);
            ret = max(ret, R[i+1] + 1);

            auto x = (A[i-1] + A[i+1]) / 2;
            if(x * 2 != A[i-1] + A[i+1]) continue;

            int l = (i == 1 || A[i-1] - A[i-2] != x - A[i-1]) ? 1 : L[i-1];
            int r = (i == n-2 || A[i+1] - x != A[i+2] - A[i+1]) ? 1 : R[i+1];
            ret = max(ret, l + r + 1);
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
