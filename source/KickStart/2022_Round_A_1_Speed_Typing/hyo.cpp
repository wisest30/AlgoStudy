#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    string I, P;
    cin >> I >> P;

    int i = 0, j = 0, ret = 0;
    while(i < I.size()) {
        if(j >= P.size()) {
            cout << "IMPOSSIBLE\n";
            return;
        }

        if(I[i] == P[j])
            ++i, ++j;
        else
            ++j, ++ret;
    }

    ret += (int)P.size() - j;
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
