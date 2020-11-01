#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 101;
int n, A[MAX_N];
void solve(int TestCase) {
    cin >> n;
    for(auto i = 0; i < n; ++i) cin >> A[i];
    for(auto i = n-1; i >= 0; --i)
        if(i >= n/2) cout << -A[i] << " ";
        else cout << A[i] << " ";
    cout << endl;
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
 
