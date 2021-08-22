#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s;
    cin >> s;

    int n = s.size();

    map<char, int> m;
    for(auto c : s)
        m[c]++;

    priority_queue<pair<int, char>> q;
    for(auto& p : m)
        q.push({p.second, p.first});
    
    if(q.top().first * 2 > n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    string ret;
    for(auto i = 0; i < n - 1; ++i) {
        auto [cnt, c] = q.top();
        q.pop();

        if(s[i] == c) {
            auto temp = q.top();
            q.pop();
            q.push({cnt, c});
            tie(cnt, c) = temp;
        }

        ret.push_back(c);
        if(cnt)
            q.push({cnt-1, c});
    }

    ret.push_back(q.top().second);
    if(s.back() == ret.back()) {
        for(auto i = 0; i < n-1; ++i) {
            if(s[i] != ret.back() && ret[i] != ret.back()) {
                swap(ret[i], ret[n-1]);
                break;
            }
        }
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
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
