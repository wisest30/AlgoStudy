#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> getP(string&& s) {
    auto ret = vector<int>(s.size());
    for(auto i = 0, j = 1; j < s.size(); ++j) {
        while(i && s[i] != s[j])
            i = ret[i-1];
        
        if(s[i] == s[j])
            ret[j] = ++i;
    }
 
    return ret;
}
 
void solve() {
    int n;
    cin >> n;
    
    auto S = vector<string>(n);
    for(auto& s : S)
        cin >> s;
 
    auto ret = string{};
    for(auto& s : S) {
        auto l = min(s.size(), ret.size());
        auto p = getP(s + ret.substr(ret.size() - l));
        auto k = p.back();
        while(k && k > l)
            k = p[k-1];
        ret += s.substr(k);
    }
 
    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
//    int t;
//    cin >> t;
//    while(t--)
        solve();
}
