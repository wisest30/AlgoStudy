#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<double> A(n);
    for(auto& a : A) cin >> a;

    sort(A.begin(), A.end());

    double ret = 0;
    for(auto i = 0; i < m - 1; ++i) {
        ret += A.back();
        A.pop_back();
    }

    if(A.size() % 2 == 0)
        ret += (A[A.size() / 2 - 1] + A[A.size() / 2]) / 2;
    else
        ret += A[A.size() / 2];

    cout.precision(15);
    cout << fixed;
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
