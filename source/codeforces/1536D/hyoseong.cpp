#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<int> B(n);
    for(auto& x : B)
        cin >> x;

    set<int> s;
    s.insert(B[0]);
    for(auto i = 1; i < n; ++i) {
        s.insert(B[i]);
        bool ok = B[i] == B[i-1];
        ok |= next(s.find(B[i])) == s.find(B[i-1]);
        ok |= next(s.find(B[i-1])) == s.find(B[i]);

        if(!ok) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
