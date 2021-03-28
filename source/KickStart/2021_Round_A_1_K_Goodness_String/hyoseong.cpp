#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int score = 0;
    for(auto i = 0; i < n / 2; ++i) {
        auto j = n - i - 1;
        if(s[i] != s[j]) score++;
    }

    auto ret = abs(k - score);
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
