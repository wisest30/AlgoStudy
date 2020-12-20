#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    ll k;
    cin >> k;

    if(k % 2) {
        cout << -1 << endl;
        return;
    }

    vector<int> ret;
    while(k) {
        int cnt = 1;
        ll cur = 2;
        while(cur * 2 + 2 <= k)
            cnt++, cur = cur * 2 + 2;
        
        ret.push_back(1);
        for(auto i = 0; i < cnt - 1; ++i)
            ret.push_back(0);
        
        k -= cur;
    }

    cout << ret.size() << endl;
    for(auto r : ret)
        cout << r << " ";
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
