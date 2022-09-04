#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int r, c;
    cin >> r >> c;

    bool is_empty = true;
    vector<string> board(r);
    for(auto& s : board) {
        cin >> s;
        is_empty &= s.find('^') == string::npos;
    }

    if(is_empty || r > 1 && c > 1) {
        cout << "Possible" << endl;
        for(auto& s : board)
            cout << (is_empty ? s : string(c, '^')) << endl;
    } else {
        cout << "Impossible" << endl;
    }
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


