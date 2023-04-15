#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    string s0, s1;
    cin >> s0 >> s1;

    while(s0.back() == '.' && s1.back() == '.') {
        s0.pop_back();
        s1.pop_back();
        --n;
    }
  
    vector<int> dp0(n+1), dp1(n+1);

    auto first = 0;
    while(s0[first] == '.' && s1[first] == '.')
        ++first;

    dp0[first+1] = s1[first] == '*';
    dp1[first+1] = s0[first] == '*';
    for(auto i = first+1; i < n; ++i) {
        dp0[i+1] = min(dp0[i] + 1 + (s1[i] == '*'), dp1[i] + 2);
        dp1[i+1] = min(dp1[i] + 1 + (s0[i] == '*'), dp0[i] + 2);
    }

    auto ret = min(dp0[n], dp1[n]);
    cout << ret << endl;
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
