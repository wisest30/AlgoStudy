#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    string ret;
    int cnt = 0;
    char prev = '_';
    for(auto i = 0; i < s.size(); ++i) {
        if(s[i] == prev) {
            ++cnt;
        } else {
            cnt = 1;
            prev = s[i];
        }

        ret.push_back(s[i]);
        if(i + 1 < s.size() && s[i+1] > s[i]) {
            for(auto j = 0; j < cnt; ++j)
                ret.push_back(s[i]);
        }        
    }

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
