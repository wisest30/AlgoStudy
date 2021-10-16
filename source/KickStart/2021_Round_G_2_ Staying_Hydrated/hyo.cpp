#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> X(2 * n), Y(2 * n);
    for(auto i = 0; i < n; ++i)
        cin >> X[i] >> Y[i] >> X[i+n] >> Y[i+n];

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int ret_x = X[n-1], ret_y = Y[n-1];

    cout << ret_x << " " << ret_y << endl;
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
