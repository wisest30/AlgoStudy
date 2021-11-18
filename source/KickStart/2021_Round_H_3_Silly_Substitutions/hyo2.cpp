#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    string s;
    cin >> n >> s;

    auto nxt = [](auto c) {
        return c == '9' ? '0' : (c+1);
    };

    set<int> S;
    for(auto i = 0; i < n; ++i) S.insert(i);

    vector<set<int>> AS(10);
    for(auto i = 0; i < n-1; ++i)
        if(nxt(s[i]) == s[i+1])
            AS[s[i] - '0'].insert(i);

    while(true) {
        auto old_size = S.size();
        for(auto x = 0; x <= 9; ++x) {
            vector<int> refresh;
            for(auto i : AS[x]) {
                auto p = S.find(i);
                auto j = *next(p);
                s[j] = nxt(s[j]);
                refresh.push_back(j);

                if(p != S.begin())
                    refresh.push_back(*prev(p));
                S.erase(p);
            }
            AS[x].clear();

            for(auto i : refresh) {
                for(auto& as : AS)
                    as.erase(i);
                
                auto p = S.find(i);
                if(next(p) != S.end() && nxt(s[i]) == s[*next(p)])
                    AS[s[i] - '0'].insert(i);
            }
        }

        if(old_size == S.size())
            break;
    }

    string ret;
    for(auto i : S)
        ret.push_back(s[i]);
    
    cout << ret << '\n';
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
