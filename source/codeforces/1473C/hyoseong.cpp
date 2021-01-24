#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;

    cin >> n >> k;

    vector<int> ret(k);
    iota(ret.begin(), ret.end(), 1);

    reverse(ret.end() - (n - k + 1), ret.end());

    for(auto x : ret) cout << x << " ";
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
