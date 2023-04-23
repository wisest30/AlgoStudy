#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string s;
    cin >> s;

    vector<string> S;
    string cur;
    for(auto ch : s) {
        if(!cur.empty() && cur.back() == ch) {
            S.push_back(cur);
            cur.clear();
        }

        cur.push_back(ch);
    }
    S.push_back(cur);
    sort(S.begin(), S.end(), [&](auto& l, auto& r) {
        return l.size() < r.size();
    });

    auto remove_2chr = [&](auto& s, char first, char second, int& x) {
        while(s.size() >= 2 && s[s.size() - 2] == first && s.back() == second && x > 0) {
            s.pop_back();
            s.pop_back();
            x--;
        }
    };

    for(auto& s : S) {
        if(s.size() == 1) {
            if(s[0] == 'A') a--;
            else if(s[0] == 'B') b--;
            s.clear();
        } else if(s.size() == 2) {
            if(s == "AB") {
                if(c > 0) c--;
                else a--, b--;
            } else if(s == "BA") {
                if(d > 0) d--;
                else a--, b--;
            }
            s.clear();
        } else if(s.size() % 2 == 0) {
            remove_2chr(s, 'A', 'B', c);
            remove_2chr(s, 'B', 'A', d);
        }
    }

    for(auto& s : S) {
        remove_2chr(s, 'A', 'B', c);
        remove_2chr(s, 'B', 'A', d);
    }

    for(auto& s : S) {
        reverse(s.begin(), s.end());

        remove_2chr(s, 'B', 'A', c);
        remove_2chr(s, 'A', 'B', d);

        reverse(s.begin(), s.end());
    }

    for(auto& s : S) {
        if(s.empty()) continue;
        if(s.back() == 'A') {
            --a;
            s.pop_back();
        } else if(s.back() == 'B') {
            --b;
            s.pop_back();
        }

        remove_2chr(s, 'A', 'B', c);
        remove_2chr(s, 'B', 'A', d);

        while(!s.empty()) {
            if(s.back() == 'A') {
                --a;
                s.pop_back();
            } else if(s.back() == 'B') {
                --b;
                s.pop_back();
            }
        }
    }

    auto ret = a == 0 && b == 0 && c == 0 && d == 0;
    cout << (ret ? "YES" : "NO") << endl;
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
