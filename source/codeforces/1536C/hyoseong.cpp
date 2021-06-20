#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(int TestCase) {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
 
    vector<int> ret;
    uint32_t dCnt = 0, kCnt = 0;
    map<pair<int, int>, int> m;
    for(auto c : s) {
        c == 'D' ? dCnt++ : kCnt++;
        auto g = __gcd(dCnt, kCnt);
        int d = dCnt / g, k = kCnt / g;
        ret.push_back(++m[make_pair(d, k)]);
    }
 
    for(auto x : ret)
        cout << x << " ";
    cout << endl;
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
