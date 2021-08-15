#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    int k = m + 1;
    int ret = 0;
    for(auto i = 31; i >= 0; --i) {
        bool a = n & (1 << i);
        bool b = k & (1 << i);

        if(!a && b) ret |= 1 << i;
        else if(a && !b) break;
    }

    cout << ret << '\n';
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
