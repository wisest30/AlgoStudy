#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int n = s.size(), ret = 0, kick = 0;
    for(auto i = 0; i < n; ++i) {
        if(i + 4 <= n && s.substr(i, 4) == "KICK")
            kick++;
        else if(i + 5 <= n && s.substr(i, 5) == "START")
            ret += kick;
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
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}

