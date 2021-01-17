#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& x : A) cin >> x;

    auto f = [&](int i) {
        if(i <= 0 || i >= n-1) return 0;
        if(A[i] > A[i-1] && A[i] > A[i+1]) return 1;
        if(A[i] < A[i-1] && A[i] < A[i+1]) return 1;
        return 0;
    };

    int cnt = 0;
    for(auto i = 0; i < n; ++i)
        cnt += f(i);

    int ret = cnt;
    for(auto i = 1; i < n-1; ++i) {
        int x = cnt - f(i-1) - f(i) - f(i+1);
        auto old = A[i];

        A[i] = A[i-1];
        ret = min(ret, x + f(i-1) + f(i) + f(i+1));
        A[i] = A[i+1];
        ret = min(ret, x + f(i-1) + f(i) + f(i+1));

        A[i] = old;
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
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
