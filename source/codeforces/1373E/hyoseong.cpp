#include<bits/stdc++.h>
 
using namespace std;

void solve(int TestCase) {
    long long n, k;
    cin >> n >> k;
    long long ret = numeric_limits<long long>::max();
    for(auto last = 0; last <= 9; ++last) {
        auto nnn = n;
        for(auto i = 0; i <= k; ++i) nnn -= (last + i) % 10;
        for(auto cnt = 0; cnt <= 17; ++ cnt) {
            long long nn = nnn;
            nn -= cnt * 9 * (last + k >= 10 ? 10-last:k+1);
            long long a = k+1, b = 0;
            if(last+k >= 10) a = 10-last, b = k+1-a;
            nn -= b;
            if(nn<0 || nn % (k+1)) continue;
            long long x = nn / (k+1);
            string s = to_string(last) + string(cnt, '9');
            if(x >= 8) {
                s.push_back('8');
                x -= 8;
            }
            while(x) {
                if(x < 10) {
                    s.push_back(x + '0');
                    break;
                }
                else {
                    s.push_back('9');
                    x -= 9;
                }
            }
            reverse(s.begin(), s.end());
            long long candi = stoll(s);
            ret = min(ret, candi);
        }
    }
    if(ret == numeric_limits<long long>::max())
        ret = -1;
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
