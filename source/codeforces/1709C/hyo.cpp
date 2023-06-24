#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int n = s.size(), a = 0, b = 0;
    for(auto c : s) {
        if(c == '(') a++;
        else if(c == ')') b++;
    }
    a = n / 2 - a, b = n / 2 - b;

    if(a == 0 || b == 0) {
        cout << "YES" << endl;
        return;
    }

    int i = 0;
    while(a > 1) {
        if(s[i] == '?') {
            s[i] = '(';
            a--;
        }
        ++i;
    }

    while(s[i] != '?') ++i;
    s[i] = ')', b--;

    while(i < n) {
        if(s[i] == '?') {
            if(a) s[i] = '(', a--;
            else s[i] = ')', b--;
        }
        ++i;
    }

    auto p = 0;
    for(auto c : s) {
        if(c == '(') ++p;
        else --p;

        if(p < 0) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
