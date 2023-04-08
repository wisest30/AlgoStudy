#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

pair<int, int> f(string s, char prev) {
    pair<int, int> ret;
    for(auto i = 0; i < s.size(); i += 2) {
        if(s[i] != s[i+1]) {
            ret.first++;
            s[i] = s[i+1] = prev;
        }

        prev = s[i];
    }

    ret.second = 1;
    for(auto i = 0; i + 1 < s.size(); ++i)
        if(s[i] != s[i+1])
            ret.second++;

    return ret;
}

void solve(int TestCase) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    auto ret = min(f(s, '0'), f(s, '1'));
    cout << ret.first << " " << ret.second << endl;
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
