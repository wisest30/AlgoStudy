#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 1010;
int n, A[MAX_N];
void solve(int TestCase) { 
    cin >> n;
    for(auto i = 0; i < n; ++i) cin >> A[i];
    sort(A, A + n);
    for(auto i = 0; i < n-1; ++i)
        if(A[i] == A[i+1]) {
            cout << "YES" << endl;
            return;
        }
    
    cout << "NO" << endl;
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
