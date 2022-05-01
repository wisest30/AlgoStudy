#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<string> A(n);
    for(auto& s: A) cin >> s;

    vector<char> prev_char(26), nxt_char(26);
    vector<vector<bool>> M(26, vector<bool>(26));
    for(auto& s : A) {
        for(auto i = 1; i < s.size(); ++i) {
            if(s[i-1] != s[i]) {
                if(nxt_char[s[i - 1] - 'A'] || prev_char[s[i] - 'A']) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }

                nxt_char[s[i - 1] - 'A'] = s[i];
                prev_char[s[i] - 'A'] = s[i-1];
            }
        }
    }

    string order;
    for(auto i = 0; i < 26; ++i) {
        if(!prev_char[i]) {
            order.push_back('A' + i);

            int cur = i;
            while(nxt_char[cur]) {
                order.push_back(nxt_char[cur]);
                cur = nxt_char[cur] - 'A';
            }
        }
    }

    if(order.size() != 26) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    map<char, int> counter;
    for(auto& s : A)
        for(auto c : s)
            counter[c]++;
    
    string ret;
    for(auto c : order)
        ret += string(counter[c], c);

    cout << ret << "\n";
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

