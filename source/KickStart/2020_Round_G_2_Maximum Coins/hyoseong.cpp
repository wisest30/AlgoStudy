#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 1000;
ll A[MAX_N][MAX_N];
void solve(int TestCase) {
    int n;
    cin >> n;

    ll ret = 0;
    for(auto i = 0; i < n; ++i) {
        for(auto j = 0; j < n; ++j) {
            cin >> A[i][j];
            
            if(i > 0 && j > 0)
                A[i][j] += A[i-1][j-1];
            
            ret = max(ret, A[i][j]);
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

