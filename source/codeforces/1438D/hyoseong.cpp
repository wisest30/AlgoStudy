#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MAX_N = 1e5 + 10;
int n, A[MAX_N];
void solve(int TestCase) {
    cin >> n;
    for(auto i = 0; i < n; ++i) cin >> A[i];

    if(n % 2 == 0) {
        int x = 0;
        for(auto a : A) x ^= a;
        if(x) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    cout << (n - 1) / 2 * 2 << endl;
    for(auto p = 0; p < 2; ++p)
        for(auto i = 0; i < (n - 1) / 2; ++i)
            cout << 1 << " " << (2 * i + 2) << " " << (2 * i + 3) << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
