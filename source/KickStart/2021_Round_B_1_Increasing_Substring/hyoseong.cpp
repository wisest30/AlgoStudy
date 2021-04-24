#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ret(n);
    ret[0] = 1;

    for(auto i = 1; i < n; ++i)
        ret[i] = s[i-1] < s[i] ? ret[i-1] + 1 : 1;
    
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
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
