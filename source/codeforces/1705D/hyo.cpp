#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    if(s[0] != t[0] || s.back() != t.back()) {
        cout << -1 << endl;
        return;
    }

    auto range = [&](string& s) {
        vector<pair<int, int>> ret;
        for(auto i = 0; i < n; ++i) {
            if(s[i] == '0') continue;
            auto j = i;
            while(j < n && s[j] == '1')
                ++j;
            ret.emplace_back(i, j);
            i = j - 1;
        }

        return ret;
    };

    auto A = range(s), B = range(t);
    if(A.size() != B.size()) {
        cout << -1 << endl;
        return;
    }

    ll ret = 0;
    for(auto i = 0; i < A.size(); ++i) {
        ret += abs(A[i].first - B[i].first);
        ret += abs(A[i].second - B[i].second);
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
