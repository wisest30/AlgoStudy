#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

// 조화 수열의 합
double h(double n) {
    double ret = 0;
    for(auto i = 1; i <= min(n, 1e7); ++i)
        ret += (double)1 / i;

    if(n > 1e7)
        ret += log(n+1) - log(1e7+1);

    return ret;
}

void solve(int TestCase) {
    double n = 0;
    cin >> n;
    
    double ret = h(n);

    cout << fixed;
    cout.precision(15);
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
