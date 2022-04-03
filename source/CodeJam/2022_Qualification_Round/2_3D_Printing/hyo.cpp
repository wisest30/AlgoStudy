#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    vector<int> colors(4, INT_MAX);
    for(auto i = 0; i < 3; ++i) {
        for(auto j = 0; j < 4; ++j) {
            int c;
            cin >> c;
            colors[j] = min(colors[j], c);
        }
    }

    auto su = accumulate(colors.begin(), colors.end(), 0);
    if(su < 1e6) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(auto i = 0; i < 4; ++i) {
        if(su > 1e6) {
            auto d = min(su - 1000000, colors[i]);
            su -= d;
            colors[i] -= d;
        }
    }

    for(auto c : colors)
        cout << c << " ";
    cout << "\n";
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
