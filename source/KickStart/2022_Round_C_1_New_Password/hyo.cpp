#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    string s;
    cin >> n >> s;
    bool upper = false, lower = false, digit = false, special = false;
    for(auto c : s) {
        if(c >= 'a' && c <= 'z') lower = true;
        else if(c >= 'A' && c <= 'Z') upper = true;
        else if (c >= '0' && c <= '9') digit = true;
        else special = true;
    }

    if(!lower) s.push_back('a');
    if(!upper) s.push_back('A');
    if(!digit) s.push_back('0');
    if(!special) s.push_back('@');
    while(s.size() < 7) s.push_back('a');

    cout << s << endl;
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
