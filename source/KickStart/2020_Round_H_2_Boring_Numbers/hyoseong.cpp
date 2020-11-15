#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

string s[2];
ll dp[2][30][30][2];
ll f(int type, int start, int cur, bool small) {
    auto& ss = s[type];
    if(cur == ss.size()) return 1;

    ll& ret = dp[type][start][cur][small];
    if(ret != -1) return ret;
    ret = 0;
    if((cur - start) % 2 == 0) { // odd
        if(small) {
            for(auto i = 1; i <= 9; i += 2)
                ret += f(type, start, cur + 1, small);
        }
        else {
            for(auto i = 1; i < ss[cur] - '0'; i += 2)
                ret += f(type, start, cur + 1, true);
            if((ss[cur] - '0') % 2 == 1)
                ret += f(type, start, cur + 1, false);
        }
    }
    else {
        if(small) {
            for(auto i = 0; i <= 8; i += 2) {
                if(cur == start && i == 0) continue;
                ret += f(type, start, cur + 1, small);
            }
        }
        else {
            for(auto i = 0; i < ss[cur] - '0'; i += 2) {
                if(cur == start && i == 0) continue;
                ret += f(type, start, cur + 1, true);
            }
            if((ss[cur] - '0') % 2 == 0)
                if(!(cur == start && ss[cur] == '0'))
                    ret += f(type, start, cur + 1, false);
        }
    }

    return ret;
}

void solve(int TestCase) {
    memset(dp, -1, sizeof(dp));
    ll l, r;
    cin >> l >> r;

    s[0] = to_string(l-1);
    s[1] = to_string(r);

    ll ret = 0;
    for(auto i = 0; i < s[1].size(); ++i) {
        ret += f(1, i, i, i > 0);
    }
    
    for(auto i = 0; i < s[0].size(); ++i)
        ret -= f(0, i, i, i > 0);
    
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
