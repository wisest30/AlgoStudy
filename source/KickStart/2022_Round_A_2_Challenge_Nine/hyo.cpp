#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int su = 0;
    for(auto c : s)
        su += c - '0';
    
    int add = 9 - su % 9;
    if(add == 9)
        add = 0;
    
    char c = add + '0';
    int n = s.size();
    if(c == '0') {
        s.insert(s.begin() + 1, c);
    } else {
        int idx = s.size();
        for(auto i = 0; i < n; ++i) {
            if(c < s[i]) {
                idx = i;
                break;
            }
        }

        s.insert(s.begin() + idx, c);
    }

    cout << s << "\n";
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
