#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    char last = '_';
    auto cnt = 0;
    for(auto c : s) {
        if(c == 'F') {
            continue;
        } else if(last != c) {
            ++cnt;
            last = c;
        }
    }

    cout << max(0, cnt - 1) << "\n";
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
