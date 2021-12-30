#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int ret = INT_MAX;
    // even
    {
        int cnt[2] = {0, 0};
        for(auto i = 0; i < n; ++i) {
            if(a[i] == b[i]) continue;
            cnt[a[i] - '0']++;
        }

        if(cnt[0] == cnt[1])
            ret = min(ret, cnt[0] + cnt[1]);
    }
    // odd
    {
        int cnt[2] = {0, 0};
        for(auto i = 0; i < n; ++i) {
            if(a[i] != b[i]) continue;
            cnt[a[i] - '0']++;
        }

        if(cnt[0] + 1 == cnt[1])
            ret = min(ret, cnt[0] + cnt[1]);
    }

    if(ret == INT_MAX)
        ret = -1;
    
    cout << ret << "\n";
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
