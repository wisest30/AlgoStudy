#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int f(char c) {
    if(c == 'R') return 1;
    else if(c == 'Y') return 2;
    else if(c == 'B') return 4;
    else if(c == 'U') return 0;
    else if(c == 'O') return 3;
    else if(c == 'P') return 5;
    else if(c == 'G') return 6;
    else if(c == 'A') return 7;
    else return -1;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> A(n);
    for(auto i = 0; i < n; ++i)
        A[i] = f(s[i]);

    int ret = 0;
    for(auto x = 1; x <= 4; x *= 2) {
        int cnt = 0;
        bool prev = false;
        for(auto i = 0; i < n; ++i) {
            bool cur = (A[i] & x) > 0;
            if(cur && !prev) ++cnt;
            prev = cur;
        }
        ret += cnt;
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
