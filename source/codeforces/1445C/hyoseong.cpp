#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

ll p, q;
void solve(int TestCase) {
    cin >> p >> q;

    if(p % q) {
        cout << p << endl;
        return;
    }

    auto A = vector<pair<int, int>>{};
    for(auto i = 2; i * i <= q; ++i) {
        while(q % i == 0) {
            q /= i;
            if(!A.empty() && A.back().first == i)
                A.back().second++;
            else
                A.push_back({i, 1});
        }
    }

    if(q > 1) A.push_back({q, 1});

    ll ret = 1;
    for(auto& a : A) {
        ll candi = p;
        while(candi % a.first == 0) candi /= a.first;
        for(auto i = 0; i < a.second - 1; ++i) candi *= a.first;
        ret = max(ret, candi);
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
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
