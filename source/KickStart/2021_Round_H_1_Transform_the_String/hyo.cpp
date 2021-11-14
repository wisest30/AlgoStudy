#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s, f;
    cin >> s >> f;
    
    vector<int> cost(26, INT_MAX);
    for(auto c : f) cost[c - 'a'] = 0;
    for(auto i = 0; i < 26; ++i) {
        for(auto j = 0; j < 26; ++j) {
            if(cost[j] == 0) {
                cost[i] = min(cost[i], abs(i - j));
                cost[i] = min(cost[i], 26 - abs(i - j));
            }
        }
    }

    int ret = 0;
    for(auto c : s)
        ret += cost[c - 'a'];
    
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
