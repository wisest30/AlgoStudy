#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& x : A) cin >> x;

    int ret = 0;
    for(auto i = 0; i < n-1; ++i) {
        auto j = min_element(A.begin() + i, A.end()) - A.begin();
        ret += j + 1 - i;
        reverse(A.begin() + i, A.begin() + j + 1);
    }

    cout << ret << endl;
}
 
int main() {
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
