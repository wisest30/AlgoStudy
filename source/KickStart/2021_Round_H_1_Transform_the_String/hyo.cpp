#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string s, f;
    cin >> s >> f;

    vector<int> cost(26, INT_MAX);
    for(auto c0 = 'a'; c0 <= 'z'; ++c0) {
        for(auto c1 : f) {
            int d = abs(c0 - c1);
            cost[c0 - 'a'] = min(cost[c0 - 'a'], min(d, 26 - d));
        }
    }

    int ret = 0;
    for(auto c : s)
        ret += cost[c - 'a'];
    
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
