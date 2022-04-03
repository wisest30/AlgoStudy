#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& x : A) cin >> x;
    sort(A.begin(), A.end());

    int ret = 0;
    for(auto& a : A)
        if(a > ret)
            ++ret;
    
    cout << ret << "\n";
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
