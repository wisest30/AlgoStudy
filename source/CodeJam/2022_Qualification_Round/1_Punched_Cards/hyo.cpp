#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int r, c;
    cin >> r >> c;

    vector<string> ret(r * 2 + 1);
    for(auto i = 0; i < ret.size(); ++i) {
        if(i % 2 == 0) {
            for(auto j = 0; j < 2 * c + 1; ++j)
                ret[i].push_back(j % 2 == 0 ? '+' : '-');
        } else {
            for(auto j = 0; j < 2 * c + 1; ++j)
                ret[i].push_back(j % 2 == 0 ? '|' : '.');
        }
    }

    ret[0][0] = ret[0][1] = ret[1][0] = '.';
    cout << "\n";
    for(auto& r : ret)
        cout << r << "\n";
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
