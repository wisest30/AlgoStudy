#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int x;
double w, e;
double dp[61][61][61];
char ans[61][61][61];

double recur(int rc, int sc, int pc) {
    if(rc + sc + pc == 60)
        return 0.0;
    
    auto& ret = dp[rc][sc][pc];
    if(ret != -1)
        return ret;

    double pr = 1.0 / 3, ps = 1.0 / 3, pp = 1.0 / 3;
    if(rc + sc + pc) {
        int t = rc + sc + pc;
        pr = (double)sc / t;
        ps = (double)pc / t;
        pp = (double)rc / t;
    }

    auto candi0 = recur(rc + 1, sc, pc) + w * ps + e * pr;
    auto candi1 = recur(rc, sc + 1, pc) + w * pp + e * ps;
    auto candi2 = recur(rc, sc, pc + 1) + w * pr + e * pp;

    ret = max(max(candi0, candi1), candi2);
    if(ret == candi0)
        ans[rc][sc][pc] = 'R';
    else if(ret == candi1)
        ans[rc][sc][pc] = 'S';
    else
        ans[rc][sc][pc] = 'P';

    return ret;
}

void solve(int TestCase) {
    cin >> w >> e;

    for(auto i = 0; i <= 60; ++i)
        for(auto j = 0; j <= 60; ++j)
            for(auto k = 0; k <= 60; ++k)
                dp[i][j][k] = -1;

    auto max_val = recur(0, 0, 0);

    string ret;
    int rc = 0, sc = 0, pc = 0;
    for(auto i = 0; i < 60; ++i) {
        char c = ans[rc][sc][pc];
        ret.push_back(c);
        if(c == 'R') rc++;
        else if(c == 'S') sc++;
        else pc++;
    }

    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    cin >> x;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
