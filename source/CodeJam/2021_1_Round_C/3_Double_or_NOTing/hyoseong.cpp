#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    constexpr int inf = 1000000;

    string s, e;
    cin >> s >> e;

    if(s == e) {
        cout << 0 << endl;
        return;
    }

    int add = 0;
    if(s == "0") s = "1", add++;

    auto ret = inf;
    int op1_cnt = 0;
    for(auto i = 0; i <= s.size(); ++i) {
        if(i > 0 && i < s.size() && s[i] == s[i-1]) continue;
        if(i > 0) op1_cnt++;

        auto t = s.substr(i);
        if(op1_cnt % 2)
            for(auto& c : t)
                c = c == '0' ? '1' : '0';

        if(t == e) {
            ret = min(ret, op1_cnt);
            continue;
        }
        
        if(t.empty() && e == "0") {
            ret = min(ret, op1_cnt);
            continue;
        }

        if(!t.empty() && e.find(t) != 0) continue;

        int cnt = 1;
        for(auto j = t.size() + 1; j < e.size(); ++j)
            if(j > 0 && e[j] != e[j-1]) cnt++;
        
        if(cnt > op1_cnt + 1) continue;
        else if(cnt == op1_cnt + 1) {
            if(e[t.size()] == '0' && op1_cnt % 2) continue;
            if(e[t.size()] == '1' && op1_cnt % 2 == 0) continue;
        }

        ret = min(ret, op1_cnt + (int)(e.size() - t.size()));
    }

    ret += add;
    if(ret >= inf) cout << "IMPOSSIBLE" << endl;
    else cout << ret << endl;
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
