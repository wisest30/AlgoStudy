#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int n = s.size();
    sort(s.begin(), s.end());
    if(n % 2 == 1) {
        for(auto i = 0; i < n; ++i) {
            if(s[i] != '0') {
                swap(s[0], s[i]);
                break;
            }
        }
        reverse(s.begin() + n / 2 + 1, s.end());
        auto ret = stoull(s.substr(0, n / 2 + 1)) - stoull(s.substr(n / 2 + 1));
        cout << ret << endl;
    }
    else {
        vector<int> same;
        for(auto i = 0; i < (int)s.size() - 1;) {
            if(s[i] != s[i+1]) i++;
            else {
                same.push_back(s[i] - '0');
                i += 2;
            }
        }

        if(same.size() * 2 == s.size()) {
            cout << 0 << endl;
            return;
        }

        auto ret = numeric_limits<uint64_t>::max();
        for(auto subset = 0; subset < (1 << same.size()); ++subset) {
            vector<int> cnt(10);
            for(auto c : s)
                cnt[c - '0']++;

            auto maxSame = -1;
            for(auto i = 0; i < same.size(); ++i) {
                if(subset & (1 << i)) {
                    cnt[same[i]] -= 2;
                    maxSame = max(maxSame, same[i]);
                }
            }
            if(maxSame == 0) continue;

            for(auto d0 = 0; d0 < 10; ++d0) {
                if(cnt[d0] == 0) continue;
                cnt[d0]--;

                for(auto d1 = 0; d1 < d0; ++d1) {
                    if(cnt[d1] == 0) continue;
                    if(subset == 0 && d1 == 0) continue;
                    cnt[d1]--;

                    int su = 0;
                    for(auto c : cnt)
                        su += c;

                    uint64_t a = d0, b = d1;
                    int len = 0;
                    for(auto i = 0; i < 10; ++i)
                        for(auto j = 0; j < cnt[i] && len < su / 2; ++j, ++len)
                            a = a * 10 + i;
                    
                    len = 0;
                    for(auto i = 9; i >= 0; --i)
                        for(auto j = 0; j < cnt[i] && len < su / 2; ++j, ++len)
                            b = b * 10 + i;

                    ret = min(ret, a - b);

                    cnt[d1]++;
                }

                cnt[d0]++;
            }
        }

        cout << ret << endl;
    }
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
