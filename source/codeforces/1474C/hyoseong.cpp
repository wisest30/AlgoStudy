#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {    
    int n;
    cin >> n;

    vector<int> A(2 * n);
    for(auto& x : A) cin >> x;

    for(auto first : A) {
        multiset<int> s(A.begin(), A.end());
        auto x = first + *s.rbegin();
        auto initial_x = x;

        vector<pair<int, int>> ret;
        while(!s.empty()) {
            auto p = *s.rbegin();
            s.erase(s.find(p));

            auto q = x - p;

            if(s.find(q) == s.end()) break;
            s.erase(s.find(q));

            ret.push_back({p, q});
            x = p;
        }

        if(s.empty()) {
            cout << "YES" << endl;
            cout << initial_x << endl;
            for(auto& p : ret) cout << p.first << " " << p.second << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
