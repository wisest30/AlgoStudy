#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int64_t ret = 0, cnt0 = 0, cnt1 = 0;
    for(auto i = 0; i < s.size(); ++i) {
        auto c = s[i];
        cnt0 = (c == '?' || c - '0' == i % 2) ? cnt0 + 1 : 0;
        cnt1 = (c == '?' || c - '0' != i % 2) ? cnt1 + 1 : 0;
        
        ret += max(cnt0, cnt1);
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
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
